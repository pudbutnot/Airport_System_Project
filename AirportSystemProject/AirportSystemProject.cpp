#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Airport.h"
#include "DataLoader.h"

#include "SearchManager.h"


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

    vector<Airport> airports = loadAirports("airports.csv");

    string code;
    cout << "Enter country code to search: ";
    cin >> code;

    vector<Airport> resultsCountry = searchByCountry(airports, code);
    cout << "Found " << resultsCountry.size() << " airports.\n";
    for (const auto& a : resultsCountry) {
        a.print();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string partial;
    cout << "\nEnter partial name: ";
    getline(cin, partial);

    vector<Airport> resultsName = searchByPartialName(airports, partial);
    cout << "Partial name matches: " << resultsName.size() << "\n";
    for (const auto& a : resultsName) {
        a.print();
    }
    string iata;
    cout << "\nEnter IATA code:\n> ";
    getline(cin, iata);

    vector<Airport> resultsIATA = searchByIATA(airports, iata);
    cout << "\nIATA matches: " << resultsIATA.size() << "\n";
    for (const auto& a : resultsIATA) {
        a.print();
    }

    cout << "\nCounting airports by type...\n";
    countAirportsByType(airports);

    return 0;
}

