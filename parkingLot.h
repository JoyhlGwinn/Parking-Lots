#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "car.h"
#include "customer.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ParkingLot {
private:
    int lotCapacity;
    int currentOccupancy;
    Car** parkedCars;

public:
    ParkingLot(int capacity);
    ~ParkingLot();

    bool isAvailable(int spot);
    void assignCar(int spot, Car* car);
    void releaseSpot(int spot);
    void displayStatus() const;

    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
    void updateFile(const string& filename) const;
};

#endif // PARKINGLOT_H
