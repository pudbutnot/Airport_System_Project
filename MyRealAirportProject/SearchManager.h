#pragma once
#ifndef SEARCH_MANAGER_H
#define SEARCH_MANAGER_H

#include <vector>
#include <string>
#include "Airport.h"

// Search airports by ISO country code
std::vector<Airport> searchByCountry(const std::vector<Airport>& airports, const std::string& country);

// Search airports by partial name (case-insensitive)
std::vector<Airport> searchByPartialName(const std::vector<Airport>& airports, const std::string& partial);

// Search airports by IATA code
std::vector<Airport> searchByIATA(const std::vector<Airport>& airports, const std::string& iata);

#endif