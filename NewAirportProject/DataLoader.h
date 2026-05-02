#pragma once
#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include <vector>
#include <string>
#include "Airport.h"

std::vector<Airport> loadAirports(const std::string& filename);
void saveAirports(const std::string& filename, const std::vector<Airport>& airports);
void addAirport(std::vector<Airport>& airports, const Airport& a);

#endif
