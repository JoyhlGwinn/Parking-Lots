#include "ParkingLot.h"
#include <iostream>
using namespace std; 

ParkingLot::ParkingLot(int capacity)
    : lotCapacity(capacity), currentOccupancy(0) {
    // Initialize arrays
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