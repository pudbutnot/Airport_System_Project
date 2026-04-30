#include "SearchManager.h"
#include <algorithm>

std::vector<Airport> searchByCountry(const std::vector<Airport>& airports, const std::string& countryCode) {
    std::vector<Airport> results;

    for (const auto& a : airports) {
        if (a.iso_country == countryCode) {
            results.push_back(a);
        }
    }

    return results;
}
