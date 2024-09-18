#ifndef PARKINGLOT_H
#define PARKINGLOT_H
#include "car.h"
#include <string>
using namespace std;

class ParkingLot {
    private:
    string lotName;
    int lotCapacity;
    int currentOccupancy;
    int** parkingTimes;
    int** car;


};
#endif