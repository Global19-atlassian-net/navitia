#include "tz_db_wrapper.h"
#include <sstream>

namespace ed {

namespace utils {

std::stringstream&& get_tz_stream();

boost::local_time::tz_database fill_tz_db() {
    boost::local_time::tz_database tzdb;

    //close your eyes...
    //Note: I did not manage to wrap this in a function returning the stringstream because gcc laks the stringstream move constructor
    std::stringstream ss;

    // no header for string init
    //"ID,STD ABBR,STD NAME,DST ABBR,DST NAME,GMT offset,DST adjustment,DST Start Date rule,Start time,DST End date rule,End time"
    ss    << "Africa/Abidjan,GMT,GMT,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Accra,GMT,GMT,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Addis_Ababa,EAT,EAT,,,+03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Algiers,CET,CET,,,+01:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Asmera,EAT,EAT,,,+03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Bamako,GMT,GMT,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Bangui,WAT,WAT,,,+01:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Banjul,GMT,GMT,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Bissau,GMT,GMT,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Blantyre,CAT,CAT,,,+02:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Brazzaville,WAT,WAT,,,+01:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Bujumbura,CAT,CAT,,,+02:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Cairo,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;5;4,+00:00:00,-1;5;9,+00:00:00" << "\n"
          << "Africa/Casablanca,WET,WET,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Ceuta,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Africa/Conakry,GMT,GMT,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Dakar,GMT,GMT,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Dar_es_Salaam,EAT,EAT,,,+03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Djibouti,EAT,EAT,,,+03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Douala,WAT,WAT,,,+01:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/El_Aaiun,WET,WET,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Freetown,GMT,GMT,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Gaborone,CAT,CAT,,,+02:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Harare,CAT,CAT,,,+02:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Johannesburg,SAST,SAST,,,+02:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Kampala,EAT,EAT,,,+03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Khartoum,EAT,EAT,,,+03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Kigali,CAT,CAT,,,+02:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Kinshasa,WAT,WAT,,,+01:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Lagos,WAT,WAT,,,+01:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Libreville,WAT,WAT,,,+01:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Lome,GMT,GMT,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Luanda,WAT,WAT,,,+01:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Lubumbashi,CAT,CAT,,,+02:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Lusaka,CAT,CAT,,,+02:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Malabo,WAT,WAT,,,+01:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Maputo,CAT,CAT,,,+02:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Maseru,SAST,SAST,,,+02:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Mbabane,SAST,SAST,,,+02:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Mogadishu,EAT,EAT,,,+03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Monrovia,GMT,GMT,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Nairobi,EAT,EAT,,,+03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Ndjamena,WAT,WAT,,,+01:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Niamey,WAT,WAT,,,+01:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Nouakchott,GMT,GMT,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Ouagadougou,GMT,GMT,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Porto-Novo,WAT,WAT,,,+01:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Sao_Tome,GMT,GMT,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Timbuktu,GMT,GMT,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Tripoli,EET,EET,,,+02:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Tunis,CET,CET,,,+01:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Africa/Windhoek,WAT,WAT,WAST,WAST,+01:00:00,+01:00:00,1;0;9,+02:00:00,1;0;4,+02:00:00" << "\n"
          << "America/Adak,HAST,HAST,HADT,HADT,-10:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Anchorage,AKST,AKST,AKDT,AKDT,-09:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Anguilla,AST,AST,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Antigua,AST,AST,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Araguaina,BRT,BRT,BRST,BRST,-03:00:00,+01:00:00,2;0;10,+00:00:00,3;0;2,+00:00:00" << "\n"
          << "America/Aruba,AST,AST,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Asuncion,PYT,PYT,PYST,PYST,-04:00:00,+01:00:00,1;0;10,+00:00:00,1;0;3,+00:00:00" << "\n"
          << "America/Barbados,AST,AST,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Belem,BRT,BRT,,,-03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Belize,CST,CST,,,-06:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Boa_Vista,AMT,AMT,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Bogota,COT,COT,,,-05:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Boise,MST,MST,MDT,MDT,-07:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Buenos_Aires,ART,ART,,,-03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Cambridge_Bay,MST,MST,MDT,MDT,-07:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Cancun,CST,CST,CDT,CDT,-06:00:00,+01:00:00,1;0;4,+02:00:00,-1;0;10,+02:00:00" << "\n"
          << "America/Caracas,VET,VET,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Catamarca,ART,ART,,,-03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Cayenne,GFT,GFT,,,-03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Cayman,EST,EST,,,-05:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Chicago,CST,Central Standard Time,CDT,Central Daylight Time,-06:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Chihuahua,MST,MST,MDT,MDT,-07:00:00,+01:00:00,1;0;4,+02:00:00,-1;0;10,+02:00:00" << "\n"
          << "America/Cordoba,ART,ART,,,-03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Costa_Rica,CST,CST,,,-06:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Cuiaba,AMT,AMT,AMST,AMST,-04:00:00,+01:00:00,2;0;10,+00:00:00,3;0;2,+00:00:00" << "\n"
          << "America/Curacao,AST,AST,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Danmarkshavn,GMT,GMT,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Dawson,PST,PST,PDT,PDT,-08:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Dawson_Creek,MST,MST,,,-07:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Denver,MST,Mountain Standard Time,MDT,Mountain Daylight Time,-07:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Detroit,EST,EST,EDT,EDT,-05:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Dominica,AST,AST,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Edmonton,MST,MST,MDT,MDT,-07:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Eirunepe,ACT,ACT,,,-05:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/El_Salvador,CST,CST,,,-06:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Fortaleza,BRT,BRT,BRST,BRST,-03:00:00,+01:00:00,2;0;10,+00:00:00,3;0;2,+00:00:00" << "\n"
          << "America/Glace_Bay,AST,AST,ADT,ADT,-04:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Godthab,WGT,WGT,WGST,WGST,-03:00:00,+01:00:00,-1;6;3,+22:00:00,-1;6;10,+23:00:00" << "\n"
          << "America/Goose_Bay,AST,AST,ADT,ADT,-04:00:00,+01:00:00,1;0;4,+00:01:00,-1;0;10,+00:01:00" << "\n"
          << "America/Grand_Turk,EST,EST,EDT,EDT,-05:00:00,+01:00:00,1;0;4,+00:00:00,-1;0;10,+00:00:00" << "\n"
          << "America/Grenada,AST,AST,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Guadeloupe,AST,AST,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Guatemala,CST,CST,,,-06:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Guayaquil,ECT,ECT,,,-05:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Guyana,GYT,GYT,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Halifax,AST,AST,ADT,ADT,-04:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Havana,CST,CST,CDT,CDT,-05:00:00,+01:00:00,1;0;4,+00:00:00,-1;0;10,+01:00:00" << "\n"
          << "America/Hermosillo,MST,MST,,,-07:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Indiana/Indianapolis,EST,EST,,,-05:00:00,+00:00:00,2;0;3,,1;0;11,+00:00:00" << "\n"
          << "America/Indiana/Knox,EST,EST,,,-05:00:00,+00:00:00,2;0;3,,1;0;11,+00:00:00" << "\n"
          << "America/Indiana/Marengo,EST,EST,,,-05:00:00,+00:00:00,2;0;3,,1;0;11,+00:00:00" << "\n"
          << "America/Indiana/Vevay,EST,EST,,,-05:00:00,+00:00:00,2;0;3,,1;0;11,+00:00:00" << "\n"
          << "America/Indianapolis,EST,EST,,,-05:00:00,+00:00:00,2;0;3,,1;0;11,+00:00:00" << "\n"
          << "America/Inuvik,MST,MST,MDT,MDT,-07:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Iqaluit,EST,EST,EDT,EDT,-05:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Jamaica,EST,EST,,,-05:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Jujuy,ART,ART,,,-03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Juneau,AKST,AKST,AKDT,AKDT,-09:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Kentucky/Louisville,EST,EST,EDT,EDT,-05:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Kentucky/Monticello,EST,EST,EDT,EDT,-05:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/La_Paz,BOT,BOT,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Lima,PET,PET,,,-05:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Los_Angeles,PST,Pacific Standard Time,PDT,Pacific Daylight Time,-08:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Louisville,EST,EST,EDT,EDT,-05:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Maceio,BRT,BRT,BRST,BRST,-03:00:00,+01:00:00,2;0;10,+00:00:00,3;0;2,+00:00:00" << "\n"
          << "America/Managua,CST,CST,,,-06:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Manaus,AMT,AMT,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Martinique,AST,AST,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Mazatlan,MST,MST,MDT,MDT,-07:00:00,+01:00:00,1;0;4,+02:00:00,-1;0;10,+02:00:00" << "\n"
          << "America/Mendoza,ART,ART,,,-03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Menominee,CST,CST,CDT,CDT,-06:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Merida,CST,CST,CDT,CDT,-06:00:00,+01:00:00,1;0;4,+02:00:00,-1;0;10,+02:00:00" << "\n"
          << "America/Mexico_City,CST,CST,CDT,CDT,-06:00:00,+01:00:00,1;0;4,+02:00:00,-1;0;10,+02:00:00" << "\n"
          << "America/Miquelon,PMST,PMST,PMDT,PMDT,-03:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Monterrey,CST,CST,CDT,CDT,-06:00:00,+01:00:00,1;0;4,+02:00:00,-1;0;10,+02:00:00" << "\n"
          << "America/Montevideo,UYT,UYT,,,-03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Montreal,EST,EST,EDT,EDT,-05:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Montserrat,AST,AST,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Nassau,EST,EST,EDT,EDT,-05:00:00,+01:00:00,1;0;4,+02:00:00,-1;0;10,+02:00:00" << "\n"
          << "America/New_York,EST,Eastern Standard Time,EDT,Eastern Daylight Time,-05:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Nipigon,EST,EST,EDT,EDT,-05:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Nome,AKST,AKST,AKDT,AKDT,-09:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Noronha,FNT,FNT,,,-02:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/North_Dakota/Center,CST,CST,CDT,CDT,-06:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Panama,EST,EST,,,-05:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Pangnirtung,EST,EST,EDT,EDT,-05:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Paramaribo,SRT,SRT,,,-03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Phoenix,MST,Mountain Standard Time,,,-07:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Port-au-Prince,EST,EST,,,-05:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Port_of_Spain,AST,AST,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Porto_Velho,AMT,AMT,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Puerto_Rico,AST,AST,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Rainy_River,CST,CST,CDT,CDT,-06:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Rankin_Inlet,CST,CST,CDT,CDT,-06:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Recife,BRT,BRT,BRST,BRST,-03:00:00,+01:00:00,2;0;10,+00:00:00,3;0;2,+00:00:00" << "\n"
          << "America/Regina,CST,CST,,,-06:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Rio_Branco,ACT,ACT,,,-05:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Rosario,ART,ART,,,-03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Santiago,CLT,CLT,CLST,CLST,-04:00:00,+01:00:00,2;0;10,+00:00:00,2;0;3,+00:00:00" << "\n"
          << "America/Santo_Domingo,AST,AST,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Sao_Paulo,BRT,BRT,BRST,BRST,-03:00:00,+01:00:00,3;0;10,+00:00:00,3;0;2,+00:00:00" << "\n"
          << "America/Scoresbysund,EGT,EGT,EGST,EGST,-01:00:00,+01:00:00,-1;0;3,+00:00:00,-1;0;10,+01:00:00" << "\n"
          << "America/Shiprock,MST,MST,MDT,MDT,-07:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/St_Johns,NST,NST,NDT,NDT,-03:30:00,+01:00:00,1;0;4,+00:01:00,-1;0;10,+00:01:00" << "\n"
          << "America/St_Kitts,AST,AST,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/St_Lucia,AST,AST,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/St_Thomas,AST,AST,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/St_Vincent,AST,AST,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Swift_Current,CST,CST,,,-06:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Tegucigalpa,CST,CST,,,-06:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Thule,AST,AST,,,-04:00:00,+00:00:00,2;0;3,,1;0;11,+00:00:00" << "\n"
          << "America/Thunder_Bay,EST,EST,EDT,EDT,-05:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Tijuana,PST,PST,PDT,PDT,-08:00:00,+01:00:00,1;0;4,+02:00:00,-1;0;10,+02:00:00" << "\n"
          << "America/Toronto,EST,EST,EDT,EDT,-05:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n" // Link to Montreal
          << "America/Tortola,AST,AST,,,-04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "America/Vancouver,PST,PST,PDT,PDT,-08:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Whitehorse,PST,PST,PDT,PDT,-08:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Winnipeg,CST,CST,CDT,CDT,-06:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+03:00:00" << "\n"
          << "America/Yakutat,AKST,AKST,AKDT,AKDT,-09:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "America/Yellowknife,MST,MST,MDT,MDT,-07:00:00,+01:00:00,2;0;3,+02:00:00,1;0;11,+02:00:00" << "\n"
          << "Antarctica/Casey,WST,WST,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Antarctica/Davis,DAVT,DAVT,,,+07:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Antarctica/DumontDUrville,DDUT,DDUT,,,+10:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Antarctica/Mawson,MAWT,MAWT,,,+06:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Antarctica/McMurdo,NZST,NZST,NZDT,NZDT,+12:00:00,+01:00:00,1;0;10,+02:00:00,3;0;3,+03:00:00" << "\n"
          << "Antarctica/Palmer,CLT,CLT,CLST,CLST,-04:00:00,+01:00:00,2;0;10,+00:00:00,2;0;3,+00:00:00" << "\n"
          << "Antarctica/South_Pole,NZST,NZST,NZDT,NZDT,+12:00:00,+01:00:00,1;0;10,+02:00:00,3;0;3,+03:00:00" << "\n"
          << "Antarctica/Syowa,SYOT,SYOT,,,+03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Antarctica/Vostok,VOST,VOST,,,+06:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Arctic/Longyearbyen,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Asia/Aden,AST,AST,,,+03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Almaty,ALMT,ALMT,ALMST,ALMST,+06:00:00,+01:00:00,-1;0;3,+00:00:00,-1;0;10,+00:00:00" << "\n"
          << "Asia/Amman,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;4;3,+00:00:00,-1;4;9,+01:00:00" << "\n"
          << "Asia/Anadyr,ANAT,ANAT,ANAST,ANAST,+12:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Asia/Aqtau,AQTT,AQTT,AQTST,AQTST,+04:00:00,+01:00:00,-1;0;3,+00:00:00,-1;0;10,+00:00:00" << "\n"
          << "Asia/Aqtobe,AQTT,AQTT,AQTST,AQTST,+05:00:00,+01:00:00,-1;0;3,+00:00:00,-1;0;10,+00:00:00" << "\n"
          << "Asia/Ashgabat,TMT,TMT,,,+05:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Baghdad,AST,AST,ADT,ADT,+03:00:00,+01:00:00,1;0;4,+03:00:00,1;0;10,+04:00:00" << "\n"
          << "Asia/Bahrain,AST,AST,,,+03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Baku,AZT,AZT,AZST,AZST,+04:00:00,+01:00:00,-1;0;3,+01:00:00,-1;0;10,+01:00:00" << "\n"
          << "Asia/Bangkok,ICT,ICT,,,+07:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Beirut,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;0;3,+00:00:00,-1;0;10,+00:00:00" << "\n"
          << "Asia/Bishkek,KGT,KGT,KGST,KGST,+05:00:00,+01:00:00,-1;0;3,+02:30:00,-1;0;10,+02:30:00" << "\n"
          << "Asia/Brunei,BNT,BNT,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Calcutta,IST,IST,,,+05:30:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Choibalsan,CHOT,CHOT,,,+09:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Chongqing,CST,CST,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Colombo,LKT,LKT,,,+06:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Damascus,EET,EET,EEST,EEST,+02:00:00,+01:00:00,1;0;4,+00:00:00,1;0;10,+00:00:00" << "\n"
          << "Asia/Dhaka,BDT,BDT,,,+06:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Dili,TPT,TPT,,,+09:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Dubai,GST,GST,,,+04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Dushanbe,TJT,TJT,,,+05:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Gaza,EET,EET,EEST,EEST,+02:00:00,+01:00:00,3;5;4,+00:00:00,3;5;10,+00:00:00" << "\n"
          << "Asia/Harbin,CST,CST,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Hong_Kong,HKT,HKT,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Hovd,HOVT,HOVT,,,+07:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Irkutsk,IRKT,IRKT,IRKST,IRKST,+08:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Asia/Istanbul,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;0;3,+03:00:00,-1;0;10,+04:00:00" << "\n"
          << "Asia/Jakarta,WIT,WIT,,,+07:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Jayapura,EIT,EIT,,,+09:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Jerusalem,IST,IST,IDT,IDT,+02:00:00,+01:00:00,1;0;4,+01:00:00,1;0;10,+01:00:00" << "\n"
          << "Asia/Kabul,AFT,AFT,,,+04:30:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Kamchatka,PETT,PETT,PETST,PETST,+12:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Asia/Karachi,PKT,PKT,,,+05:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Kashgar,CST,CST,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Katmandu,NPT,NPT,,,+05:45:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Krasnoyarsk,KRAT,KRAT,KRAST,KRAST,+07:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Asia/Kuala_Lumpur,MYT,MYT,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Kuching,MYT,MYT,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Kuwait,AST,AST,,,+03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Macao,CST,CST,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Macau,CST,CST,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Magadan,MAGT,MAGT,MAGST,MAGST,+11:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Asia/Makassar,CIT,CIT,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Manila,PHT,PHT,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Muscat,GST,GST,,,+04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Nicosia,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;0;3,+03:00:00,-1;0;10,+04:00:00" << "\n"
          << "Asia/Novosibirsk,NOVT,NOVT,NOVST,NOVST,+06:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Asia/Omsk,OMST,OMST,OMSST,OMSST,+06:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Asia/Oral,WST,WST,,,+05:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Phnom_Penh,ICT,ICT,,,+07:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Pontianak,WIT,WIT,,,+07:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Pyongyang,KST,KST,,,+09:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Qyzylorda,KST,KST,,,+06:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Qatar,AST,AST,,,+03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Rangoon,MMT,MMT,,,+06:30:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Riyadh,AST,AST,,,+03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Saigon,ICT,ICT,,,+07:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Sakhalin,SAKT,SAKT,SAKST,SAKST,+10:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Asia/Samarkand,UZT,UZT,,,+05:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Seoul,KST,KST,,,+09:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Shanghai,CST,CST,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Singapore,SGT,SGT,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Taipei,CST,CST,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Tashkent,UZT,UZT,,,+05:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Tbilisi,GET,GET,GEST,GEST,+04:00:00,+01:00:00,-1;0;3,+00:00:00,-1;0;10,+00:00:00" << "\n"
          << "Asia/Tehran,IRT,IRT,,,+03:30:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Thimphu,BTT,BTT,,,+06:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Tokyo,JST,JST,,,+09:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Ujung_Pandang,CIT,CIT,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Ulaanbaatar,ULAT,ULAT,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Urumqi,CST,CST,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Vientiane,ICT,ICT,,,+07:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Asia/Vladivostok,VLAT,VLAT,VLAST,VLAST,+10:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Asia/Yakutsk,YAKT,YAKT,YAKST,YAKST,+09:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Asia/Yekaterinburg,YEKT,YEKT,YEKST,YEKST,+05:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Asia/Yerevan,AMT,AMT,AMST,AMST,+04:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Atlantic/Azores,AZOT,AZOT,AZOST,AZOST,-01:00:00,+01:00:00,-1;0;3,+00:00:00,-1;0;10,+01:00:00" << "\n"
          << "Atlantic/Bermuda,AST,AST,ADT,ADT,-04:00:00,+01:00:00,1;0;4,+02:00:00,-1;0;10,+02:00:00" << "\n"
          << "Atlantic/Canary,WET,WET,WEST,WEST,+00:00:00,+01:00:00,-1;0;3,+01:00:00,-1;0;10,+02:00:00" << "\n"
          << "Atlantic/Cape_Verde,CVT,CVT,,,-01:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Atlantic/Faeroe,WET,WET,WEST,WEST,+00:00:00,+01:00:00,-1;0;3,+01:00:00,-1;0;10,+02:00:00" << "\n"
          << "Atlantic/Jan_Mayen,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Atlantic/Madeira,WET,WET,WEST,WEST,+00:00:00,+01:00:00,-1;0;3,+01:00:00,-1;0;10,+02:00:00" << "\n"
          << "Atlantic/Reykjavik,GMT,GMT,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Atlantic/South_Georgia,GST,GST,,,-02:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Atlantic/St_Helena,GMT,GMT,,,+00:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Atlantic/Stanley,FKT,FKT,FKST,FKST,-04:00:00,+01:00:00,1;0;9,+02:00:00,3;0;4,+02:00:00" << "\n"
          << "Australia/Adelaide,CST,CST,CST,CST,+09:30:00,+01:00:00,1;0;10,+02:00:00,1;0;4,+03:00:00" << "\n"
          << "Australia/Brisbane,EST,EST,,,+10:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Australia/Broken_Hill,CST,CST,CST,CST,+09:30:00,+01:00:00,1;0;10,+02:00:00,1;0;4,+03:00:00" << "\n"
          << "Australia/Darwin,CST,CST,,,+09:30:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Australia/Eucla,CWST,CWST,,,+08:45:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Australia/Hobart,EST,EST,EST,EST,+10:00:00,+01:00:00,1;0;10,+02:00:00,1;0;4,+03:00:00" << "\n"
          << "Australia/Lindeman,EST,EST,,,+10:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Australia/Lord_Howe,LHST,LHST,LHST,LHST,+10:30:00,+00:30:00,1;0;10,+02:00:00,1;0;4,+02:30:00" << "\n"
          << "Australia/Melbourne,EST,EST,EST,EST,+10:00:00,+01:00:00,1;0;10,+02:00:00,1;0;4,+03:00:00" << "\n"
          << "Australia/Perth,WST,WST,,,+08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Australia/Sydney,EST,EST,EST,EST,+10:00:00,+01:00:00,1;0;10,+02:00:00,1;0;4,+03:00:00" << "\n"
          << "Europe/Amsterdam,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Andorra,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Athens,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;0;3,+03:00:00,-1;0;10,+04:00:00" << "\n"
          << "Europe/Belfast,GMT,GMT,BST,BST,+00:00:00,+01:00:00,-1;0;3,+01:00:00,-1;0;10,+02:00:00" << "\n"
          << "Europe/Belgrade,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Berlin,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Bratislava,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Brussels,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Bucharest,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;0;3,+03:00:00,-1;0;10,+04:00:00" << "\n"
          << "Europe/Budapest,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Chisinau,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;0;3,+03:00:00,-1;0;10,+04:00:00" << "\n"
          << "Europe/Copenhagen,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Dublin,GMT,GMT,IST,IST,+00:00:00,+01:00:00,-1;0;3,+01:00:00,-1;0;10,+02:00:00" << "\n"
          << "Europe/Gibraltar,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Helsinki,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;0;3,+03:00:00,-1;0;10,+04:00:00" << "\n"
          << "Europe/Istanbul,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;0;3,+03:00:00,-1;0;10,+04:00:00" << "\n"
          << "Europe/Kaliningrad,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Kiev,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;0;3,+03:00:00,-1;0;10,+04:00:00" << "\n"
          << "Europe/Lisbon,WET,WET,WEST,WEST,+00:00:00,+01:00:00,-1;0;3,+01:00:00,-1;0;10,+02:00:00" << "\n"
          << "Europe/Ljubljana,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/London,GMT,GMT,BST,BST,+00:00:00,+01:00:00,-1;0;3,+01:00:00,-1;0;10,+02:00:00" << "\n"
          << "Europe/Luxembourg,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Madrid,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Malta,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Minsk,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Monaco,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Moscow,MSK,MSK,MSD,MSD,+03:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Nicosia,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;0;3,+03:00:00,-1;0;10,+04:00:00" << "\n"
          << "Europe/Oslo,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Paris,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Prague,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Riga,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;0;3,+03:00:00,-1;0;10,+04:00:00" << "\n"
          << "Europe/Rome,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Samara,SAMT,SAMT,SAMST,SAMST,+04:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/San_Marino,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Sarajevo,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Simferopol,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;0;3,+03:00:00,-1;0;10,+04:00:00" << "\n"
          << "Europe/Skopje,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Sofia,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;0;3,+03:00:00,-1;0;10,+04:00:00" << "\n"
          << "Europe/Stockholm,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Tallinn,EET,EET,,,+02:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Europe/Tirane,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Uzhgorod,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;0;3,+03:00:00,-1;0;10,+04:00:00" << "\n"
          << "Europe/Vaduz,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Vatican,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Vienna,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Vilnius,EET,EET,,,+02:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Europe/Warsaw,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Zagreb,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Europe/Zaporozhye,EET,EET,EEST,EEST,+02:00:00,+01:00:00,-1;0;3,+03:00:00,-1;0;10,+04:00:00" << "\n"
          << "Europe/Zurich,CET,CET,CEST,CEST,+01:00:00,+01:00:00,-1;0;3,+02:00:00,-1;0;10,+03:00:00" << "\n"
          << "Indian/Antananarivo,EAT,EAT,,,+03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Indian/Chagos,IOT,IOT,,,+06:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Indian/Christmas,CXT,CXT,,,+07:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Indian/Cocos,CCT,CCT,,,+06:30:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Indian/Comoro,EAT,EAT,,,+03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Indian/Kerguelen,TFT,TFT,,,+05:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Indian/Mahe,SCT,SCT,,,+04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Indian/Maldives,MVT,MVT,,,+05:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Indian/Mauritius,MUT,MUT,,,+04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Indian/Mayotte,EAT,EAT,,,+03:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Indian/Reunion,RET,RET,,,+04:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Apia,WST,WST,,,-11:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Auckland,NZST,NZST,NZDT,NZDT,+12:00:00,+01:00:00,1;0;10,+02:00:00,3;0;3,+03:00:00" << "\n"
          << "Pacific/Chatham,CHAST,CHAST,CHADT,CHADT,+12:45:00,+01:00:00,1;0;10,+02:45:00,3;0;3,+03:45:00" << "\n"
          << "Pacific/Easter,EAST,EAST,EASST,EASST,-06:00:00,+01:00:00,2;6;10,+22:00:00,2;6;3,+22:00:00" << "\n"
          << "Pacific/Efate,VUT,VUT,,,+11:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Enderbury,PHOT,PHOT,,,+13:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Fakaofo,TKT,TKT,,,-10:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Fiji,FJT,FJT,,,+12:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Funafuti,TVT,TVT,,,+12:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Galapagos,GALT,GALT,,,-06:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Gambier,GAMT,GAMT,,,-09:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Guadalcanal,SBT,SBT,,,+11:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Guam,ChST,ChST,,,+10:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Honolulu,HST,HST,,,-10:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Johnston,HST,HST,,,-10:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Kiritimati,LINT,LINT,,,+14:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Kosrae,KOST,KOST,,,+11:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Kwajalein,MHT,MHT,,,+12:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Majuro,MHT,MHT,,,+12:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Marquesas,MART,MART,,,-09:30:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Midway,SST,SST,,,-11:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Nauru,NRT,NRT,,,+12:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Niue,NUT,NUT,,,-11:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Norfolk,NFT,NFT,,,+11:30:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Noumea,NCT,NCT,,,+11:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Pago_Pago,SST,SST,,,-11:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Palau,PWT,PWT,,,+09:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Pitcairn,PST,PST,,,-08:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Ponape,PONT,PONT,,,+11:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Port_Moresby,PGT,PGT,,,+10:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Rarotonga,CKT,CKT,,,-10:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Saipan,ChST,ChST,,,+10:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Tahiti,TAHT,TAHT,,,-10:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Tarawa,GILT,GILT,,,+12:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Tongatapu,TOT,TOT,,,+13:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Truk,TRUT,TRUT,,,+10:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Wake,WAKT,WAKT,,,+12:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Wallis,WFT,WFT,,,+12:00:00,+00:00:00,,,,+00:00:00" << "\n"
          << "Pacific/Yap,YAPT,YAPT,,,+10:00:00,+00:00:00,,,,+00:00:00" << "\n"
        ;


    tzdb.load_from_stream(ss);

    return tzdb;
}

}
}
