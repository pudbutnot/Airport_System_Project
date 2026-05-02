#include <iostream>
#include <vector>
#include <limits>
#include "Airport.h"
#include "DataLoader.h"
#include "SearchManager.h"

using namespace std;

Airport createAirportFromInput() {
    Airport a;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n--- Add New Airport ---\n";

    cout << "Ident: ";
    getline(cin, a.ident);

    cout << "Type: ";
    getline(cin, a.type);

    cout << "Name: ";
    getline(cin, a.name);

    cout << "Elevation (ft): ";
    getline(cin, a.elevation_ft);

    cout << "Continent: ";
    getline(cin, a.continent);

    cout << "ISO Country: ";
    getline(cin, a.iso_country);

    cout << "ISO Region: ";
    getline(cin, a.iso_region);

    cout << "Municipality: ";
    getline(cin, a.municipality);

    cout << "ICAO Code: ";
    getline(cin, a.icao_code);

    cout << "IATA Code: ";
    getline(cin, a.iata_code);

    cout << "GPS Code: ";
    getline(cin, a.gps_code);

    cout << "Local Code: ";
    getline(cin, a.local_code);

    cout << "Latitude: ";
    cin >> a.latitude;

    cout << "Longitude: ";
    cin >> a.longitude;

    return a;
}

void printAirport(const Airport& a) {
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

void advancedMenu(vector<Airport>& airports) {
    int choice;
    cout << "\n--- Advanced Options ---\n";
    cout << "1. Find nearest airport\n";
    cout << "2. List airports within radius\n";
    cout << "3. Highest & lowest elevation\n";
    cout << "4. Airports missing IATA\n";
    cout << "5. Sort by name\n";
    cout << "6. Sort by country\n";
    cout << "7. Sort by type\n";
    cout << "8. Sort by elevation\n";
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1) {
        double lat, lon;
        cout << "Latitude: "; cin >> lat;
        cout << "Longitude: "; cin >> lon;
        const Airport* a = findNearestAirport(airports, lat, lon);
        if (a) printAirport(*a);
    }
    else if (choice == 2) {
        double lat, lon, r;
        cout << "Latitude: "; cin >> lat;
        cout << "Longitude: "; cin >> lon;
        cout << "Radius (km): "; cin >> r;
        auto results = airportsWithinRadius(airports, lat, lon, r);
        for (auto a : results) printAirport(*a);
    }
    else if (choice == 3) {
        auto [high, low] = highestLowestElevation(airports);
        if (high && low) {
            cout << "\nHighest Elevation:\n"; printAirport(*high);
            cout << "\nLowest Elevation:\n"; printAirport(*low);
        }
        else {
            cout << "No airports loaded.\n";
        }
    }
    else if (choice == 4) {
        auto results = airportsMissingIATA(airports);
        cout << "Airports with missing IATA: " << results.size() << "\n";
        for (auto a : results) printAirport(*a);
    }
    else if (choice == 5) {
        sortByName(airports);
        cout << "Airports sorted by name.\n";
    }
    else if (choice == 6) {
        sortByCountry(airports);
        cout << "Airports sorted by country.\n";
    }
    else if (choice == 7) {
        sortByType(airports);
        cout << "Airports sorted by type.\n";
    }
    else if (choice == 8) {
        sortByElevation(airports);
        cout << "Airports sorted by elevation.\n";
    }
}

int main() {
    vector<Airport> airports = loadAirports("airports.csv");

    int choice;

    while (true) {
        cout << "\n----- Airport System -----\n";
        cout << "1. Search by Country\n";
        cout << "2. Search by Partial Name\n";
        cout << "3. Search by IATA\n";
        cout << "4. Add New Airport\n";
        cout << "5. Save\n";
        cout << "6. Advanced Options\n"; // NEW
        cout << "7. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            string code;
            cout << "Enter country code: ";
            cin >> code;

            auto results = searchByCountry(airports, code);
            cout << "Found " << results.size() << " airports.\n";

            for (const auto& a : results)
                printAirport(a);
        }
        else if (choice == 2) {
            cin.ignore();
            string partial;
            cout << "Enter partial name: ";
            getline(cin, partial);

            auto results = searchByPartialName(airports, partial);
            cout << "Found " << results.size() << " airports.\n";

            for (const auto& a : results)
                printAirport(a);
        }
        else if (choice == 3) {
            cin.ignore();
            string iata;
            cout << "Enter IATA code: ";
            getline(cin, iata);

            auto results = searchByIATA(airports, iata);
            cout << "Found " << results.size() << " airports.\n";

            for (const auto& a : results)
                printAirport(a);
        }
        else if (choice == 4) {
            Airport newAirport = createAirportFromInput();
            addAirport(airports, newAirport);

            cout << "\nAirport has been added.\n";

            char again;
            cout << "Return to menu? (y/n): ";
            cin >> again;

            if (again == 'n' || again == 'N') {
                cout << "Goodbye.\n";
                return 0;
            }
        }
        else if (choice == 5) {
            saveAirports("airports.csv", airports);

            cout << "\nAirports saved successfully.\n";

            char again;
            cout << "Return to menu? (y/n): ";
            cin >> again;

            if (again == 'n' || again == 'N') {
                cout << "Goodbye.\n";
                return 0;
            }
        }
        else if (choice == 6) {
            advancedMenu(airports); // NEW
        }
        else if (choice == 7) {
            cout << "Goodbye.\n";
            return 0;
        }
    }

    return 0;
}
