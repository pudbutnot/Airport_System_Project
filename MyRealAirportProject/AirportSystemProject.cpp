#include <iostream>
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
            cout << "Airport added.\n";
        }
        else if (choice == 5) {
            saveAirports("airports.csv", airports);
            cout << "\nAirports saved successfully.\n";

            char again;
            cout << "Return to menu? (y/n): ";
            cin >> again;

            if (again == 'n' || again == 'N') {
                cout << "Goodbye.\n";
                break;
            }
        }
    }
    return 0;
}