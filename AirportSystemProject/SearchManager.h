#pragma once
#ifndef SEARCH_MANAGER_H
#define SEARCH_MANAGER_H

#include <vector>
#include <string>
#include "Airport.h"

std::vector<Airport> searchByCountry(const std::vector<Airport>& airports, const std::string& countryCode);
std::vector<Airport> searchByPartialName(const std::vector<Airport>& airports, const std::string& partialName);
std::vector<Airport> searchByIATA(const std::vector<Airport>& airports, const std::string& iataCode);
#endif