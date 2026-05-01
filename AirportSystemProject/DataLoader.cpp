#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm> // for remove()

std::vector<Airport> loadAirports(const std::string& filename) {
    std::vector<Airport> airports;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cout << "Error: Could not open CSV file.\n";
        return airports;
    }

    // Skip header
    std::getline(file, line);

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

        if (coord.empty()) {
            a.latitude = 0;
            a.longitude = 0;
        }
        else {
            size_t commaPos = coord.find(',');

            try {
                if (commaPos != std::string::npos) {
                    a.latitude = std::stod(coord.substr(0, commaPos));
                    a.longitude = std::stod(coord.substr(commaPos + 1));
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
