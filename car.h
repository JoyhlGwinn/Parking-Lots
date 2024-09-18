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
    int enumeration;
    int year;

    public:
    car(string, string, string, string, int, int);
};

#endif