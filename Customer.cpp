#include "customer.h"

Customer::Customer (string& name, Car* customerCar, ParkingLot* spot)
    : customerName(name), car(customerCar), rentedSpot(spot){}

Customer::~Customer()
{
    releaseSpot();
}
    
void Customer::rentSpot (ParkingLot* spot)
{
    if (rentedSpot == nullptr)
    {
        rentedSpot = spot;
        cout << customerName << " is now renting the spot\n";
    }
    else
    {
        cout << "Space is already taken\n";
    }
}

void Customer::releaseSpot ()
{
    if (rentedSpot != nullptr)
    {
        rentedSpot = nullptr;
        cout << customerName << " has been released from the spot\n";
    }
    else 
    {
        cout << "There is no customer to release on that spot\n";
    }
}

string Customer::getInfo ()
{
    string customerInfo;

    cout << "What is the customer's name?\n";
    cin >> customerName;

    customerInfo = customerName+"#"+getDetails()+"#"+rentedSpot;

    return customerInfo;
}