#include "car.h"
#include <iostream>

using namespace std;

int main() {
    int userInput;

    do {
        cout << "Choose an integer 1-7 to take action. " << endl;
        cout << "\n1.) Add a customer (car) " << endl;
        cout << "\n2.) Print parking lot status " << endl;
        cout << "\n3.) Remove a customer " << endl;
        cout << "\n4.) View all customers in the parking lot " << endl;
        cout << "\n5.) End the program " << endl;

        cin >> userInput;

        if (userInput < 1 || userInput > 5) {
            cout << "\n\nChoose an integer 1-5, please. " << endl << endl;
        }
    } while (userInput < 1 || userInput > 7);

    switch (userInput) {
        case 1: {
            string make, model, licensePlate, color;

            cout << "Enter the car's make: ";
            cin >> make;
            cout << "Enter the car's model: ";
            cin >> model;
            cout << "Enter the car's license plate: ";
            cin >> licensePlate;
            cout << "Enter the car's color: ";
            cin >> color;

            // Create a new Car object with the provided information
            Car newCar(make, model, licensePlate, color);

            // Display the car details
            cout << "Customer added with car details: " << newCar.getDetails() << endl;
            break;
        }

        case 2:
            cout << "Parking lot status is unavailable." << endl;
            break;

        case 3:
            cout << "Removing a customer is unavailable." << endl;
            break;

        case 4:
            cout << "Viewing customers is unavailable." << endl;
            break;

        case 5:
            cout << "Program ended." << endl;
            return 0;
    }
    return 0;
}
