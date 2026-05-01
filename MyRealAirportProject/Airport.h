#pragma once
#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>

struct Airport {
    std::string ident;
    std::string type;
    std::string name;
    std::string elevation_ft;
    std::string continent;
    std::string iso_country;
    std::string iso_region;
    std::string municipality;
    std::string icao_code;
    std::string iata_code;
    std::string gps_code;
    std::string local_code;

    double latitude = 0;
    double longitude = 0;
};

#endif
