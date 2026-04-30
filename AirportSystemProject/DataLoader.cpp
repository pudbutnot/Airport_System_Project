#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

feature-display-data
std::vector<Airport> loadAirports(const std::string& filename) {
    std::vector<Airport> airports;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cout << "Error: Could not open CSV file.\n";
        return airports;
    }

    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Airport a;
        std::string temp;

        std::getline(ss, a.ident, ',');
        std::getline(ss, a.type, ',');
        std::getline(ss, a.name, ',');

        
        std::getline(ss, temp, ',');
        a.elevation_ft = temp.empty() ? 0 : std::stoi(temp);

        std::getline(ss, a.continent, ',');
        std::getline(ss, a.iso_country, ',');
        std::getline(ss, a.iso_region, ',');
        std::getline(ss, a.municipality, ',');
        std::getline(ss, a.icao_code, ',');
        std::getline(ss, a.iata_code, ',');
        std::getline(ss, a.gps_code, ',');
        std::getline(ss, a.local_code, ',');

        
        std::getline(ss, temp, ',');  // temp = "52.123, -1.234"

        size_t commaPos = temp.find(',');
        if (commaPos != std::string::npos) {
            std::string latStr = temp.substr(0, commaPos);
            std::string lonStr = temp.substr(commaPos + 1);

            a.latitude = latStr.empty() ? 0.0 : std::stod(latStr);
            a.longitude = lonStr.empty() ? 0.0 : std::stod(lonStr);
        }
        else {
            a.latitude = 0.0;
            a.longitude = 0.0;
        }

        airports.push_back(a);
    }

    std::cout << "Loaded: " << airports.size() << " airports.\n";
    return airports;
}
std::vector <Airport> loadAirports(const std::string& filename) {
	std::vector<Airport> airports;
	std::ifstream file(filename);
	std::string line;

	if (!file.is_open()) {
		std::cout << "Error: Could not open CSV file.\n";
		return airports;
	}

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
		std::getline(ss, a.coordinates, ',');

		airports.push_back(a);
	}
std::cout << "Loaded: " << airports.size() << " aiports.\n";
	return airports;
std::cout << "Loaded " << airports.size() << "aiports.\n";
		return airports;
}
development
