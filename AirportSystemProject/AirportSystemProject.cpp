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
    for (const auto& a : resultsCountry) {
        cout << "-----------------------------\n";
        cout << "Name: " << a.name << "\n";
        cout << "IATA: " << a.iata_code << "\n";
        cout << "ICAO: " << a.icao_code << "\n";
        cout << "Type: " << a.type << "\n";
        cout << "Country: " << a.iso_country << "\n";
        cout << "Region: " << a.iso_region << "\n";
        cout << "Municipality: " << a.municipality << "\n";
        cout << "Elevation (ft): " << a.elevation_ft << "\n";
        cout << "Latitude: " << a.latitude << "\n";
        cout << "Longitude: " << a.longitude << "\n";
    }


    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string partial;
    cout << "\nEnter partial name: ";
    getline(cin, partial);

    vector<Airport> resultsName = searchByPartialName(airports, partial);
    cout << "Partial name matches: " << resultsName.size() << "\n";
    for (const auto& a : resultsName) {
        cout << "-----------------------------\n";
        cout << "Name: " << a.name << "\n";
        cout << "IATA: " << a.iata_code << "\n";
        cout << "ICAO: " << a.icao_code << "\n";
        cout << "Type: " << a.type << "\n";
        cout << "Country: " << a.iso_country << "\n";
        cout << "Region: " << a.iso_region << "\n";
        cout << "Municipality: " << a.municipality << "\n";
        cout << "Elevation (ft): " << a.elevation_ft << "\n";
        cout << "Latitude: " << a.latitude << "\n";
        cout << "Longitude: " << a.longitude << "\n";
    }


    string iata;
    cout << "\nEnter IATA code:\n> ";
    getline(cin, iata);

    vector<Airport> resultsIATA = searchByIATA(airports, iata);
    cout << "\nIATA matches: " << resultsIATA.size() << "\n";
    for (const auto& a : resultsIATA) {
        cout << "-----------------------------\n";
        cout << "Name: " << a.name << "\n";
        cout << "IATA: " << a.iata_code << "\n";
        cout << "ICAO: " << a.icao_code << "\n";
        cout << "Type: " << a.type << "\n";
        cout << "Country: " << a.iso_country << "\n";
        cout << "Region: " << a.iso_region << "\n";
        cout << "Municipality: " << a.municipality << "\n";
        cout << "Elevation (ft): " << a.elevation_ft << "\n";
        cout << "Latitude: " << a.latitude << "\n";
        cout << "Longitude: " << a.longitude << "\n";
    }


    return 0;
}

