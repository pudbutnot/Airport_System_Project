#pragma once
#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include <vector>
#include <string>
#include "Airport.h"

// Loads all airports from the CSV file
std::vector<Airport> loadAirports(const std::string& filename);

// Saves all airports back to the CSV file
void saveAirports(const std::string& filename, const std::vector<Airport>& airports);

// Adds a new airport to the vector
void addAirport(std::vector<Airport>& airports, const Airport& a);

#endif
