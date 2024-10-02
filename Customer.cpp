#include "customer.h"
//Still need to stitch rented spot with everything else.
Customer::Customer (string& name, Car* customerCar, ParkingLot* spot)
    : customerName(name), gender(gender), age(age), car(customerCar), rentedSpot(spot){}

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

//Function to tie Customer info to Car details.
string Customer::getInfo ()
{
    string carInfo;
    string customerInfo;

    carInfo = car->getDetails();

    customerInfo = "\nName: " + customerName + "\ngender: " + gender + "\nAge: " + age;

    cout << "Customer added with customer details: " << customerInfo;

    customerInfo = customerInfo + carInfo;

    return customerInfo;

    
    //Following comments should be removed, left here in case of need
    //     string make, model, licensePlate, color;

    //     cout << "Enter the car's make: ";
    //     cin >> make;
    //     cout << "Enter the car's model: ";
    //     cin >> model;
    //     cout << "Enter the car's license plate: ";
    //     cin >> licensePlate;
    //     cout << "Enter the car's color: ";
    //     cin >> color;

    // Car newCar(make, model, licensePlate, color);
    // string CustomerCar = newCar.getDetails();

    // cout << "What is the customer's name?\n";
    // cin >> customerName;
}