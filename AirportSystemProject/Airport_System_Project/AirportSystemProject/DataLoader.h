#pragma once
#ifndef DATA_LOADER_H
#define DATA_LOADER_H
#include <vector>
#include "Airport.h"

std::vector <Airport> loadAirports(const std::string& filename);

#endif

#include <vector>
#include <string>
#include "Airport.h"

std::vector<Airport> loadAirports(const std::string& filename);

#endif

