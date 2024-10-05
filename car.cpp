#include "car.h"

Car::Car(string make, string model, string licensePlate, string color) //Read 02-CSC1310 OOP+introC++ on iLearn
: make(make), model(model), licensePlate(licensePlate), color(color) {} //Initialization by calling constructor for class and
                                                                        //create objects make, model, licenseplate, and color
string Car::getDetails() const{
    return "\nMake: " + make + "\nModel: " + model + "\nLicense Plate: " + licensePlate + "\nColor: " + color + "\n";
}
void Car::updateLicensePlate(string newPlate) {
    licensePlate = newPlate;
}

void Car::updateColor(string newColor) {
    color = newColor;
}

string Car::getMake() const {
    return make;
}

string Car::getModel() const {
    return model;
}

string Car::getLicensePlate() const {
    return licensePlate;
}

string Car::getColor() const {
    return color;
}