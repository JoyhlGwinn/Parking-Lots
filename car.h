#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string make;          
    string model;         
    string licensePlate;  
    string color;         

public:
    Car(string make, string model, string licensePlate, string color);
    
    string getDetails() const;
    
    void updateLicensePlate(string newPlate);
    void updateColor(string newColor);

    string getMake() const;
    string getModel() const;
    string getLicensePlate() const;
    string getColor() const;
};

#endif
