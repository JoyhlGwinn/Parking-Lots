#ifndef PARKINGLOT_H
#define PARKINGLOT_H
#include "car.h"
using namespace std;

class ParkingLot {
    private:
    int lotCapacity;
    int currentOccupancy;
    int* parkingTimes;
    Car** parkedCars;

public:
ParkingLot(int capacaity);
~ParkingLot();

bool isAvailable(int spot);
void assignCar(int spot, Car* car, int rentalTime);
void releaseSpot(int spot);
void displayStatus() const;

};
#endif