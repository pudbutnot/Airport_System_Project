#include "SearchManager.h"
#include <algorithm>
#include <vector>

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
void addAirport(std::vector<Airport>& airports, const Airport& a) {
    airports.push_back(a);
}