#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <fstream>
#include <string>
#include "car.h"
#include "parkingLot.cpp"

using namespace std;

class Customer
{
    private:
    string customerName;
    string gender;
    Car* car;
    ParkingLot* rentedSpot;

    public:
    Customer(string& name, Car* customerCar = nullptr, ParkingLot* spot = nullptr);
    ~Customer();

    void rentSpot (ParkingLot* spot);
    void releaseSpot ();
    string getInfo ();
    string getName() const;
    string getGender() const;
};
#endif