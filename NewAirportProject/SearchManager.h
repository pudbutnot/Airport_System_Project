#pragma once
#ifndef SEARCH_MANAGER_H
#define SEARCH_MANAGER_H

#include <vector>
#include <string>
#include "Airport.h"

// Basic search
std::vector<Airport> searchByCountry(const std::vector<Airport>& airports, const std::string& country);
std::vector<Airport> searchByPartialName(const std::vector<Airport>& airports, const std::string& partial);
std::vector<Airport> searchByIATA(const std::vector<Airport>& airports, const std::string& iata);


// Geographic calculations code
double haversine(double lat1, double lon1, double lat2, double lon2);
const Airport* findNearestAirport(const std::vector<Airport>& airports, double lat, double lon);
std::vector<const Airport*> airportsWithinRadius(const std::vector<Airport>& airports, double lat, double lon, double radiusKm);


// Data analysis code
std::pair<const Airport*, const Airport*> highestLowestElevation(const std::vector<Airport>& airports);
std::vector<const Airport*> airportsMissingIATA(const std::vector<Airport>& airports);


// Sorting code
void sortByName(std::vector<Airport>& airports);
void sortByCountry(std::vector<Airport>& airports);
void sortByType(std::vector<Airport>& airports);
void sortByElevation(std::vector<Airport>& airports);

#endif
