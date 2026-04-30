#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Airport.h"
#include "DataLoader.h"

using namespace std;

int main()
{
    std::vector <Airport> airports = loadAirports("airports.csv");
    std::string code;
    std::cout << "Enter country code to search: ";
    std::cin >> code;
    std::vector <Airport> results = searchByCountry(airports, code);

    std::cout << "Found:  " << results.size() << "airports.\n";

    for (const auto& a : results) {
        std::cout << a.name << " (" << a.iata_code << ") - " << a.municipality << "\n";
    }
    return 0;
}

    std::cout << "Program started successfully.\n";
    return 0;
}

