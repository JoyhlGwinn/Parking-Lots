#include "customer.h" //Make Varis of age/ gender... remeber to stitch details and rented spot.
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

//Sorry, not done yet. More annoying to implemet than anticipated
string Customer::getInfo ()
{
    string customerInfo;

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

    customerInfo = customerName+"#"+;//getDetails()make+model+licensePlate+color+"#";+rentedSpot; Still needs proper data from Car

    return customerInfo;
}