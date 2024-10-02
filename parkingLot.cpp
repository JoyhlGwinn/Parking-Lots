#include "ParkingLot.h"
#include <iostream>
#include <fstream>

using namespace std;

ParkingLot::ParkingLot(int capacity) : lotCapacity(capacity), currentOccupancy(0) {
    parkedCars=new Car*[capacity]();
    for (int i=0; i<capacity; ++i) {
        parkedCars[i] = nullptr;
    }
}
ParkingLot::~ParkingLot() {
    for (int i=0; i<lotCapacity; ++i) {
        delete parkedCars[i];
    }
    delete[] parkedCars;
}
bool ParkingLot::isAvailable(int spot) {
    if (spot<0 || spot>=lotCapacity) {
        return false;
    }
    return parkedCars[spot] == nullptr;
}
void ParkingLot::assignCar(int spot, Car* car) {
    if (spot<0 || spot>=lotCapacity || !isAvailable(spot)) {
        cout << "Invalid spot or spot already occupied." << endl;
        return;
    }
    parkedCars[spot]=car;
    currentOccupancy++;
}
void ParkingLot::releaseSpot(int spot) {
    if (spot<0 || spot>=lotCapacity || isAvailable(spot)) {
        cout << "Invalid spot or spot already empty." << endl;
        return;
    }
    delete parkedCars[spot];
    parkedCars[spot] = nullptr;
    currentOccupancy--;
}
void ParkingLot::displayStatus() const {
    cout << "Parking Lot Status:" << endl;
    for (int i=0; i<lotCapacity; ++i) {
        if (parkedCars[i]) {
            cout << "Spot " << i << ": Occupied" << endl;
        } else {
            cout << "Spot " << i << ": Available" << endl;
        }
    }
}

void ParkingLot::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    file << lotCapacity << " " << currentOccupancy << endl;
    for (int i = 0; i < lotCapacity; ++i) {
        if (parkedCars[i]) {
            file << i << " ";
            file << parkedCars[i]->getMake() << " "
                 << parkedCars[i]->getModel() << " "
                 << parkedCars[i]->getLicensePlate() << " "
                 << parkedCars[i]->getColor() << endl;
        }
    }
    file.close();
}

void ParkingLot::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    int capacity, occupancy;
    file >> capacity >> occupancy;

    if (capacity != lotCapacity) {
        cerr << "Mismatch in lot capacity." << endl;
        return;
    }

    // Clear current state
    for (int i = 0; i < lotCapacity; ++i) {
        delete parkedCars[i];
        parkedCars[i] = nullptr;
    }
    currentOccupancy = 0;

    // Load data
    int spot;
    string make, model, licensePlate, color;
    while (file >> spot >> make >> model >> licensePlate >> color) {
        if (spot < 0 || spot >= lotCapacity) {
            cerr << "Invalid spot in file." << endl;
            continue;
        }
        parkedCars[spot] = new Car(make, model, licensePlate, color);
        currentOccupancy++;
    }

    file.close();
}