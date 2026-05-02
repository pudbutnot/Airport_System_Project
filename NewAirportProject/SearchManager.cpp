#include "SearchManager.h"
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

// Basic search functions
string toLower(const string& s) {
    string out = s;
    transform(out.begin(), out.end(), out.begin(),
        [](unsigned char c) { return tolower(c); });
    return out;
}

vector<Airport> searchByCountry(const vector<Airport>& airports, const string& country) {
    vector<Airport> results;
    string target = toLower(country);

    for (const auto& a : airports)
        if (toLower(a.iso_country) == target)
            results.push_back(a);

    return results;
}

vector<Airport> searchByPartialName(const vector<Airport>& airports, const string& partial) {
    vector<Airport> results;
    string target = toLower(partial);

    for (const auto& a : airports)
        if (toLower(a.name).find(target) != string::npos)
            results.push_back(a);

    return results;
}

vector<Airport> searchByIATA(const vector<Airport>& airports, const string& iata) {
    vector<Airport> results;
    string target = toLower(iata);

    for (const auto& a : airports)
        if (toLower(a.iata_code) == target)
            results.push_back(a);

    return results;
}

double deg2rad(double deg) {
    return deg * 3.14159265358979323846 / 180.0;
}

double haversine(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371.0;
    double dLat = deg2rad(lat2 - lat1);
    double dLon = deg2rad(lon2 - lon1);
    lat1 = deg2rad(lat1);
    lat2 = deg2rad(lat2);

    double a = sin(dLat / 2) * sin(dLat / 2) +
        cos(lat1) * cos(lat2) *
        sin(dLon / 2) * sin(dLon / 2);

    return 2 * R * atan2(sqrt(a), sqrt(1 - a));
}

const Airport* findNearestAirport(const vector<Airport>& airports, double lat, double lon) {
    if (airports.empty()) return nullptr;

    const Airport* best = &airports[0];
    double bestDist = haversine(lat, lon, best->latitude, best->longitude);

    for (const auto& a : airports) {
        double d = haversine(lat, lon, a.latitude, a.longitude);
        if (d < bestDist) {
            bestDist = d;
            best = &a;
        }
    }
    return best;
}

vector<const Airport*> airportsWithinRadius(const vector<Airport>& airports, double lat, double lon, double radiusKm) {
    vector<const Airport*> results;
    for (const auto& a : airports) {
        if (haversine(lat, lon, a.latitude, a.longitude) <= radiusKm) {
            results.push_back(&a);
        }
    }
    return results;
}

double safeElevation(const Airport& a) {
    try { return stod(a.elevation_ft); }
    catch (...) { return 0; }
}

pair<const Airport*, const Airport*> highestLowestElevation(const vector<Airport>& airports) {
    if (airports.empty()) return { nullptr, nullptr };

    const Airport* high = &airports[0];
    const Airport* low = &airports[0];

    for (const auto& a : airports) {
        if (safeElevation(a) > safeElevation(*high)) high = &a;
        if (safeElevation(a) < safeElevation(*low))  low = &a;
    }
    return { high, low };
}

vector<const Airport*> airportsMissingIATA(const vector<Airport>& airports) {
    vector<const Airport*> results;
    for (const auto& a : airports)
        if (a.iata_code.empty())
            results.push_back(&a);
    return results;
}

void sortByName(vector<Airport>& airports) {
    sort(airports.begin(), airports.end(),
        [](const Airport& a, const Airport& b) { return a.name < b.name; });
}

void sortByCountry(vector<Airport>& airports) {
    sort(airports.begin(), airports.end(),
        [](const Airport& a, const Airport& b) { return a.iso_country < b.iso_country; });
}

void sortByType(vector<Airport>& airports) {
    sort(airports.begin(), airports.end(),
        [](const Airport& a, const Airport& b) { return a.type < b.type; });
}

void sortByElevation(vector<Airport>& airports) {
    sort(airports.begin(), airports.end(),
        [](const Airport& a, const Airport& b) { return safeElevation(a) < safeElevation(b); });
}
