#pragma once
#ifndef AIRPORT_H
#define AIPORT_H

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
	std::string coordinates;
};
#endif

#define AIRPORT_H

#include <string>
#include <iostream>

struct Airport {
    std::string ident;
    std::string type;
    std::string name;
    int elevation_ft;
    std::string continent;
    std::string iso_country;
    std::string iso_region;
    std::string municipality;
    std::string icao_code;
    std::string iata_code;
    std::string gps_code;
    std::string local_code;
    double latitude;
    double longitude;

    void print() const {
        std::cout << "----------------------------------------\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "IATA: " << iata_code << "\n";
        std::cout << "ICAO: " << icao_code << "\n";
        std::cout << "Type: " << type << "\n";
        std::cout << "Country: " << iso_country << "\n";
        std::cout << "Region: " << iso_region << "\n";
        std::cout << "Municipality: " << municipality << "\n";
        std::cout << "Elevation (ft): " << elevation_ft << "\n";
        std::cout << "Latitude: " << latitude << "\n";
        std::cout << "Longitude: " << longitude << "\n";
    }
};

#endif
