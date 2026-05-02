#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

std::vector<Airport> loadAirports(const std::string& filename) {
    std::vector<Airport> airports;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cout << "Error: Could not open CSV file.\n";
        return airports;
    }

    std::getline(file, line); // skip header

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Airport a;

        std::getline(ss, a.ident, ',');
        std::getline(ss, a.type, ',');
        std::getline(ss, a.name, ',');
        std::getline(ss, a.elevation_ft, ',');
        std::getline(ss, a.continent, ',');
        std::getline(ss, a.iso_country, ',');
        std::getline(ss, a.iso_region, ',');
        std::getline(ss, a.municipality, ',');
        std::getline(ss, a.icao_code, ',');
        std::getline(ss, a.iata_code, ',');
        std::getline(ss, a.gps_code, ',');
        std::getline(ss, a.local_code, ',');

        std::string coord;
        std::getline(ss, coord);

        coord.erase(std::remove(coord.begin(), coord.end(), ' '), coord.end());
        coord.erase(std::remove(coord.begin(), coord.end(), '"'), coord.end());

        if (!coord.empty()) {
            size_t pos = coord.find(',');
            try {
                if (pos != std::string::npos) {
                    a.latitude = std::stod(coord.substr(0, pos));
                    a.longitude = std::stod(coord.substr(pos + 1));
                }
                else {
                    a.latitude = std::stod(coord);
                    a.longitude = 0;
                }
            }
            catch (...) {
                a.latitude = 0;
                a.longitude = 0;
            }
        }

        airports.push_back(a);
    }

    std::cout << "Loaded: " << airports.size() << " airports.\n";
    return airports;
}

void saveAirports(const std::string& filename, const std::vector<Airport>& airports) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cout << "Error: Could not save CSV file.\n";
        return;
    }

    file << "ident,type,name,elevation_ft,continent,iso_country,iso_region,municipality,"
        "icao_code,iata_code,gps_code,local_code,coordinates\n";

    for (const auto& a : airports) {
        file << a.ident << ","
            << a.type << ","
            << a.name << ","
            << a.elevation_ft << ","
            << a.continent << ","
            << a.iso_country << ","
            << a.iso_region << ","
            << a.municipality << ","
            << a.icao_code << ","
            << a.iata_code << ","
            << a.gps_code << ","
            << a.local_code << ","
            << "\"" << a.latitude << "," << a.longitude << "\"\n";
    }
}

void addAirport(std::vector<Airport>& airports, const Airport& a) {
    airports.push_back(a);
}
