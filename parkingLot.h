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

public:
parkingLot(sring name, int time);
~parkingLot();

bool parkCar(int** car, int time);
void printLotStatus() const;
void setLocation(const string& location);
void removeCar(int** car);

private:
string lotLocation;

};
#endif