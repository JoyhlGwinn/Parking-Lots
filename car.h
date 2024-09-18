#ifndef CAR_H
#define CAR_H

#include <iostream>

using namespace std;

class car
{
    private:
    string licencsePlate;
    string Make;
    string Model;
    string OwnerName;
    string color;
    int year;

    public:
    car(string, string, string, string, string, int);
};

#endif