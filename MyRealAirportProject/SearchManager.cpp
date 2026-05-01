#include "SearchManager.h"
#include <algorithm>
#include <cctype>

// Helper: convert string to lowercase
static std::string toLower(const std::string& s) {
    std::string out = s;
    std::transform(out.begin(), out.end(), out.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return out;
}

// Search by ISO Country
std::vector<Airport> searchByCountry(const std::vector<Airport>& airports, const std::string& country) {
    std::vector<Airport> results;
    std::string target = toLower(country);

    for (const auto& a : airports) {
        if (toLower(a.iso_country) == target) {
            results.push_back(a);
        }
    }

    return results;
}

// Search by Partial Name
std::vector<Airport> searchByPartialName(const std::vector<Airport>& airports, const std::string& partial) {
    std::vector<Airport> results;
    std::string target = toLower(partial);

    for (const auto& a : airports) {
        if (toLower(a.name).find(target) != std::string::npos) {
            results.push_back(a);
        }
    }

    return results;
}


// Search by IATA Code
std::vector<Airport> searchByIATA(const std::vector<Airport>& airports, const std::string& iata) {
    std::vector<Airport> results;
    std::string target = toLower(iata);

    for (const auto& a : airports) {
        if (toLower(a.iata_code) == target) {
            results.push_back(a);
        }
    }

    return results;
}
