#include "ParkingLot.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std; 

ParkingLot::ParkingLot(int capacity)
    : lotCapacity(capacity), currentOccupancy(0) {
    //arrays
    parkingTimes = new int[lotCapacity]();
    parkedCars = new Car*[lotCapacity];
    for (int i = 0; i < lotCapacity; ++i) {
        parkedCars[i] = nullptr;
    }
}

ParkingLot::~ParkingLot() {
    delete[] parkingTimes;
    delete[] parkedCars;
}

bool ParkingLot::isAvailable(int spot) const {
    if (spot < 0 || spot >= lotCapacity) {
        cerr << "Invalid spot number.\n";
        return false;
    }
    return parkedCars[spot] == nullptr;
}

void ParkingLot::assignCar(int spot, Car* car, int rentalTime) {
    if (spot < 0 || spot >= lotCapacity) {
        cerr << "Invalid spot number.\n";
        return;
    }
    if (parkedCars[spot] != nullptr) {
        cerr << "Spot is already occupied.\n";
        return;
    }
    parkedCars[spot] = car;
    parkingTimes[spot] = rentalTime;
    ++currentOccupancy;
}

void ParkingLot::releaseSpot(int spot) {
    if (spot < 0 || spot >= lotCapacity) {
        cerr << "Invalid spot number.\n";
        return;
    }
    if (parkedCars[spot] == nullptr) {
        cerr << "Spot is already empty.\n";
        return;
    }
    parkedCars[spot] = nullptr;
    parkingTimes[spot] = 0;
    --currentOccupancy;
}

void ParkingLot::displayStatus() const {
    cout << "Parking Lot Status:\n";
    cout << "Capacity: " << lotCapacity << "\n";
    cout << "Current Occupancy: " << currentOccupancy << "\n";
    for (int i = 0; i < lotCapacity; ++i) {
        cout << "Spot " << i << ": ";
        if (parkedCars[i] != nullptr) {
            cout << "Occupied (rental time left: " << parkingTimes[i] << ")\n";
        } else {
            cout << "Available\n";
        }
    }
}
void ParkingLot::saveFile(const string& filename){
    ofstram outFile(filename);
    if(!outfile){
        cerr << "There was an error open file.\n";
        return;
    }
    outFile << lotCapacity << "" << currentOccupancy << "\n";
    for(int i = 0; i<lotCapacity; ++i);{
        if(parkedCars[i] !=nullptr);{
        outfile<<i<<"" << parkingTimes[i] << "\n";
        }
    }
outFile.close();
}
void ParkingLot::LoadFromFiles(const string& filename){
    ifstream inFile(filename);
    if (!infile){
        cerr << "There was an error opening the file for reading." 
    }
}