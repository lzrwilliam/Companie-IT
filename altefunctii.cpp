//
// Created by lazar on 12/1/2022.
//

#include "altefunctii.h"

char *ConvertireData(const time_t time1) {


    char *dt = ctime(&time1);
    return dt;


}

//std::tm CreazaData(int zi, int luna, int an) {
//    std::tm tm = {};
//    tm.tm_year = an - 1900;
//    tm.tm_mon = luna - 1;
//    tm.tm_mday = zi;
//    return tm;
//
//
//}

//time_t DataCurenta() {
//
//    time_t now = time(0);
//    tm *timp = localtime(&now);
//    std::tm tm2 = CreazaData(timp->tm_mday, 1 + timp->tm_mon, 1900 + timp->tm_year);
//    std::time_t time1 = mktime(&tm2);
//    return time1;
//
//
//}
