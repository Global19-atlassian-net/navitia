/* Copyright © 2001-2014, Canal TP and/or its affiliates. All rights reserved.
  
This file is part of Navitia,
    the software to build cool stuff with public transport.
 
Hope you'll enjoy and contribute to this project,
    powered by Canal TP (www.canaltp.fr).
Help us simplify mobility and open public transport:
    a non ending quest to the responsive locomotion way of traveling!
  
LICENCE: This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
   
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Affero General Public License for more details.
   
You should have received a copy of the GNU Affero General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
  
Stay tuned using
twitter @navitia 
IRC #navitia on freenode
https://groups.google.com/d/forum/navitia
www.navitia.io
*/

#include "route_schedules.h"
#include "routing/dataraptor.h"
#include "thermometer.h"
#include "request_handle.h"
#include "type/pb_converter.h"
#include "ptreferential/ptreferential.h"
#include "utils/paginate.h"
#include "type/datetime.h"
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/algorithm/sort.hpp>
#include <boost/range/algorithm_ext/for_each.hpp>
#include <boost/graph/topological_sort.hpp>
#include <boost/graph/adjacency_list.hpp>

namespace pt = boost::posix_time;

namespace navitia { namespace timetables {

static std::vector<std::vector<datetime_stop_time> >
get_all_stop_times(const std::vector<routing::JpIdx>& journey_patterns,
                   const DateTime& dateTime,
                   const DateTime& max_datetime,
                   const size_t max_stop_date_times,
                   const type::Data& d,
                   const type::RTLevel rt_level,
                   const boost::optional<const std::string> calendar_id) {
    std::vector<std::vector<datetime_stop_time> > result;

    // We take the first journey pattern points from every journey_pattern
    std::vector<routing::JppIdx> first_journey_pattern_points;
    for (const auto& jp_idx: journey_patterns) {
        const auto& jp = d.dataRaptor->jp_container.get(jp_idx);
        if (jp.jpps.empty()) { continue; }
        first_journey_pattern_points.push_back(jp.jpps.front());
    }

    std::vector<datetime_stop_time> first_dt_st;
    if(!calendar_id) {
        // If there is no calendar we get all stop times in
        // the desired timeframe
        first_dt_st = get_stop_times(routing::StopEvent::pick_up, first_journey_pattern_points,
                                     dateTime, max_datetime, max_stop_date_times, d, rt_level);
    }
    else {
        // Otherwise we only take stop_times in a vehicle_journey associated to
        // the desired calendar and in the timeframe
        first_dt_st = get_stop_times(first_journey_pattern_points, DateTimeUtils::hour(dateTime),
                                     DateTimeUtils::hour(max_datetime), d, *calendar_id);
    }

    //On va chercher tous les prochains horaires
    for(auto ho : first_dt_st) {
        result.push_back(std::vector<datetime_stop_time>());
        DateTime dt = ho.first;
        for(const type::StopTime& stop_time : ho.second->vehicle_journey->stop_time_list) {
            if(!stop_time.is_frequency()) {
                dt = DateTimeUtils::shift(dt, stop_time.departure_time);
            } else {
                // for frequencies, we only need to add the stoptime offset to the first stoptime
                dt = ho.first + stop_time.departure_time;
            }
            result.back().push_back(std::make_pair(dt, &stop_time));
        }
    }
    return result;
}

namespace {
// The score is the number of aligned cells that are not on order
// minus the number of aligned cells that are on order. Ex:
// v1 v2
//  1  2 => -1
//  2  3 => -1
//  3  4 => -1
//  5  5
//  7
//  9  7 =>  1
// score:   -2
int score(const std::vector<datetime_stop_time>& v1,
          const std::vector<datetime_stop_time>& v2) {
    int res = 0;
    boost::range::for_each(v1, v2, [&](const datetime_stop_time& a, const datetime_stop_time& b) {
            if (a.second == nullptr || b.second == nullptr) { return; }
            if (a.first < b.first) {
                --res;
            } else if (a.first > b.first) {
                ++res;
            }
        });
    return res;
}
typedef boost::adjacency_list<
    boost::vecS,
    boost::vecS,
    boost::directedS
    > Graph;
struct Edge {
    uint32_t source;
    uint32_t target;
    uint32_t score;

    friend bool operator<(const Edge& a, const Edge& b) {
        if (a.score != b.score) { return a.score > b.score; }
        if (a.source != b.source) { return a.source < b.source; }
        return a.target < b.target;
    }
};
std::vector<Edge> create_edges(std::vector<std::vector<datetime_stop_time>>& v) {
    std::vector<Edge> edges;
    for (uint32_t i = 0; i < v.size(); ++i) {
        for (uint32_t j = i + 1; j < v.size(); ++j) {
            const int s = score(v[i], v[j]);
            if (s > 0) {
                edges.push_back({i, j, uint32_t(s)});
            } else if (s < 0) {
                edges.push_back({j, i, uint32_t(-s)});
            }
        }
    }
    boost::sort(edges);
    return edges;
}
// Using http://en.wikipedia.org/wiki/Ranked_pairs to sort the vj.  As
// if each stop time vote according to the time of the vj at its stop
// time (don't care for the vj that don't stop).
std::vector<uint32_t> compute_order(const size_t nb_vertices, const std::vector<Edge>& edges) {
    Graph g(nb_vertices);
    std::vector<uint32_t> order;
    order.reserve(nb_vertices);

    // most of the time, the graph will not have any cycle, thus we
    // test directly a topological sort.
    try {
        for (const auto& edge: edges) { add_edge(edge.source, edge.target, g); }
        order.clear();
        boost::topological_sort(g, std::back_inserter(order));
        return order;
    } catch (boost::not_a_dag&) {}

    // there is a cycle, thus we run the complete algorithm.
    g = Graph(nb_vertices);// remove all edges
    for (const auto& edge: edges) {
        const auto e_desc = add_edge(edge.source, edge.target, g).first;
        try {
            order.clear();
            boost::topological_sort(g, std::back_inserter(order));
        } catch (boost::not_a_dag&) {
            remove_edge(e_desc, g);
        }
    }
    order.clear();
    topological_sort(g, std::back_inserter(order));
    return order;
}
void ranked_pairs_sort(std::vector<std::vector<datetime_stop_time>>& v) {
    const auto edges = create_edges(v);
    const auto order = compute_order(v.size(), edges);

    // reordering v according to the given order
    std::vector<std::vector<datetime_stop_time>> res;
    res.reserve(v.size());
    for (const auto& idx: order) {
        res.push_back(std::move(v[idx]));
    }
    boost::swap(res, v);
}
}

static std::vector<std::vector<datetime_stop_time> >
make_matrice(const std::vector<std::vector<datetime_stop_time> >& stop_times,
             const Thermometer& thermometer,
             const type::Data&) {
    // result group stop_times by stop_point, tmp by vj.
    const size_t thermometer_size = thermometer.get_thermometer().size();
    std::vector<std::vector<datetime_stop_time> > 
        result(thermometer_size, std::vector<datetime_stop_time>(stop_times.size())),
        tmp(stop_times.size(), std::vector<datetime_stop_time>(thermometer_size));
    // We match every stop_time with the journey pattern
    int y=0;
    for(const std::vector<datetime_stop_time>& vec : stop_times) {
        const auto* vj = vec.front().second->vehicle_journey;
        std::vector<uint32_t> orders = thermometer.stop_times_order(*vj);
        int order = 0;
        for(datetime_stop_time dt_stop_time : vec) {
            tmp.at(y).at(orders.at(order)) = dt_stop_time;
            ++order;
        }
        ++y;
    }

    ranked_pairs_sort(tmp);
    // We rotate the matrice, so it can be handle more easily in route_schedule
    for (size_t i=0; i<tmp.size(); ++i) {
        for (size_t j=0; j<tmp[i].size(); ++j) {
            result[j][i] = tmp[i][j];
        }
    }
    return result;
}

pbnavitia::Response
route_schedule(const std::string& filter,
               const boost::optional<const std::string> calendar_id,
               const std::vector<std::string>& forbidden_uris,
               const pt::ptime datetime,
               uint32_t duration, size_t max_stop_date_times,
               const uint32_t max_depth, int count, int start_page,
               const type::Data &d, const type::RTLevel rt_level, const bool show_codes) {
    RequestHandle handler(filter, forbidden_uris, datetime, duration, d, {});

    if(handler.pb_response.has_error()) {
        return handler.pb_response;
    }
    auto now = pt::second_clock::universal_time();
    auto pt_datetime = to_posix_time(handler.date_time, d);
    auto pt_max_datetime = to_posix_time(handler.max_datetime, d);
    pt::time_period action_period(pt_datetime, pt_max_datetime);
    Thermometer thermometer;
    auto routes_idx = ptref::make_query(type::Type_e::Route, filter, forbidden_uris, d);
    size_t total_result = routes_idx.size();
    routes_idx = paginate(routes_idx, count, start_page);
    for(type::idx_t route_idx : routes_idx) {
        auto route = d.pt_data->routes[route_idx];
        const auto& jps =  d.dataRaptor->jp_container.get_jps_from_route()[routing::RouteIdx(*route)];
        //On récupère les stop_times
        auto stop_times = get_all_stop_times(jps, handler.date_time,
                                             handler.max_datetime, max_stop_date_times,
                                             d, rt_level, calendar_id);
        std::vector<vector_idx> stop_points;
        for(auto jp_idx : jps) {
            const auto& jp = d.dataRaptor->jp_container.get(jp_idx);
            stop_points.push_back(vector_idx());
            for(auto jpp_idx : jp.jpps) {
                const auto& jpp = d.dataRaptor->jp_container.get(jpp_idx);
                stop_points.back().push_back(jpp.sp_idx.val);
            }
        }
        thermometer.generate_thermometer(stop_points);
        //On génère la matrice
        auto  matrice = make_matrice(stop_times, thermometer, d);
        auto schedule = handler.pb_response.add_route_schedules();
        pbnavitia::Table *table = schedule->mutable_table();
        auto m_pt_display_informations = schedule->mutable_pt_display_informations();
        fill_pb_object(route, d, m_pt_display_informations, 0, now, action_period);

        std::vector<bool> is_vj_set(stop_times.size(), false);
        for (size_t i = 0; i < stop_times.size(); ++i) { table->add_headers(); }
        for(unsigned int i=0; i < thermometer.get_thermometer().size(); ++i) {
            type::idx_t spidx=thermometer.get_thermometer()[i];
            const type::StopPoint* sp = d.pt_data->stop_points[spidx];
            //version v1
            pbnavitia::RouteScheduleRow* row = table->add_rows();
            fill_pb_object(sp, d, row->mutable_stop_point(), max_depth,
                           now, action_period, show_codes);
            for(unsigned int j=0; j<stop_times.size(); ++j) {
                datetime_stop_time dt_stop_time  = matrice[i][j];
                if (!is_vj_set[j] && dt_stop_time.second != nullptr) {
                    pbnavitia::Header* header = table->mutable_headers(j);
                    pbnavitia::PtDisplayInfo* vj_display_information = header->mutable_pt_display_informations();
                    auto vj = dt_stop_time.second->vehicle_journey;
                    fill_pb_object(vj, d, vj_display_information, dt_stop_time.second, nullptr,
                                   0, now, action_period);
                    // as we only issue headsign for vj in route_schedules:
                    // - need to override headsign with trip headsign (i.e. vj.name)
                    // - issue all headsigns of the vj in headsigns
                    vj_display_information->set_headsign(vj->name);
                    for (const auto& headsign: d.pt_data->headsign_handler.get_all_headsigns(vj)) {
                        vj_display_information->add_headsigns(headsign);
                    }
                    fill_additional_informations(header->mutable_additional_informations(),
                                                 vj->has_datetime_estimated(),
                                                 vj->has_odt(),
                                                 vj->has_zonal_stop_point());
                    is_vj_set[j] = true;
                }

                auto pb_dt = row->add_date_times();
                fill_pb_object(dt_stop_time.second, d, pb_dt, max_depth,
                               now, action_period, dt_stop_time.first);
            }
        }
        fill_pb_object(route->shape, schedule->mutable_geojson());
    }
    auto pagination = handler.pb_response.mutable_pagination();
    pagination->set_totalresult(total_result);
    pagination->set_startpage(start_page);
    pagination->set_itemsperpage(count);
    pagination->set_itemsonpage(handler.pb_response.route_schedules_size());
    return handler.pb_response;
}
}}
