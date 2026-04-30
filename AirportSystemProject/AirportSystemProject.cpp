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
    vector<Airport> airports = loadAirports("airports.csv");

    string code;
    cout << "Enter country code to search: ";
    cin >> code;

    vector<Airport> resultsCountry = searchByCountry(airports, code);
    cout << "Found " << resultsCountry.size() << " airports.\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string partial;
    cout << "\nEnter partial name: ";
    getline(cin, partial);

    vector<Airport> resultsName = searchByPartialName(airports, partial);
    cout << "Partial name matches: " << resultsName.size() << "\n";

    string iata;
    cout << "\nEnter IATA code:\n> ";
    getline(cin, iata);

    vector<Airport> resultsIATA = searchByIATA(airports, iata);
    cout << "\nIATA matches: " << resultsIATA.size() << "\n";

    return 0;
}

