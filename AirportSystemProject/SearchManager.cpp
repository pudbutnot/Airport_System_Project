#include "SearchManager.h"
#include <algorithm>

#include <map>
#include <iostream>

using std::string;
using std::vector;
using std::map;
using std::cout;

std::vector<Airport> searchByCountry(const std::vector<Airport>& airports, const std::string& countryCode) {
    std::vector<Airport> results;

    for (const auto& a : airports) {
        if (a.iso_country == countryCode) {
            results.push_back(a);
        }
    }

    return results;
}

std::vector<Airport> searchByPartialName(const std::vector<Airport>& airports, const std::string& partialName) {
    std::vector<Airport> results;

    for (const auto& a : airports) {
        std::string nameLower = a.name;
        std::string searchLower = partialName;

        std::transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);
        std::transform(searchLower.begin(), searchLower.end(), searchLower.begin(), ::tolower);

        if (nameLower.find(searchLower) != std::string::npos) {
            results.push_back(a);
        }
    }

    return results;
}

std::vector<Airport> searchByIATA(const std::vector<Airport>& airports, const std::string& iataCode) {
    std::vector<Airport> results;

    for (const auto& a : airports) {
        if (a.iata_code == iataCode) {
            results.push_back(a);
        }
    }

    return results;
}

void countAirportsByType(const std::vector<Airport>& airports) {
    std::map<std::string, int> typeCounts;

    for (const auto& a : airports) {
        typeCounts[a.type]++;
    }

    std::cout << "\nAirport counts by type:\n";
    std::cout << "----------------------------------------\n";

    for (const auto& entry : typeCounts) {
        std::cout << entry.first << ": " << entry.second << "\n";
    }
}
