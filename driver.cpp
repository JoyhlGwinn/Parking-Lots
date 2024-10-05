#include "car.h"
#include "customer.h"
#include "driver.h"
#include "parkingLot.h"

int main() {
    int userInput;
    ParkingLot lot(30);

    do {
        displayMenu();

        cout << "\nSelection: ";
        cin >> userInput;

        // Check for valid input
        while (userInput < 1 || userInput > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nInvalid input. Please choose an integer between 1 and 5." << endl;
            displayMenu();
            cout << "\nSelection: ";
            cin >> userInput;
        }

        switch (userInput) {
            case 1: {
                string make, model, licensePlate, color, name, gender;

                cout << "\nEnter the car's make: ";
                cin >> make;
                cout << "Enter the car's model: ";
                cin >> model;
                cout << "Enter the car's license plate: ";
                cin >> licensePlate;
                cout << "Enter the car's color: ";
                cin >> color;

                cout << "Enter the customer's name: ";
                cin >> name;
                cout << "Enter the customer's gender: ";
                cin >> gender;

                Car newCar(make, model, licensePlate, color);

                int assignedSpot = -1;
                for (int i = 0; i < 30; i++) {
                    if (lot.isAvailable(i)) {
                        assignedSpot = i;
                        lot.assignCar(i, &newCar);
                        break;
                    }
                }

                if (assignedSpot == -1) {
                    for (int i = 0; i < 30; i++) {
                        if (lot.isAvailable(i)) {
                            assignedSpot = i;
                            lot.assignCar(i, &newCar);
                            break;
                        }
                    }
                }

                if (assignedSpot == -1) {
                    cout << "No available spots in the parking lot." << endl;
                } else {
                    cout << "\nCustomer added with car details: " << newCar.getDetails() << endl;
                    cout << "Assigned parking spot: " << assignedSpot + 1 << endl;

                    ofstream file("parking_lot_info.txt", ios::app);
                    if (file.is_open()) {
                        file << "Customer: " << name << "\n"
                             << "Gender: " << gender << "\n"
                             << "Car Make: " << newCar.getMake() << "\n"
                             << "Car Model: " << newCar.getModel() << "\n"
                             << "License Plate: " << newCar.getLicensePlate() << "\n"
                             << "Color: " << newCar.getColor() << "\n"
                             << "Assigned Spot: " << assignedSpot + 1 << "\n"
                             << "-----------------------\n";
                             lot.loadFromFile("parking_lot_info.txt");
                        file.close();
                    } else {
                        cerr << "\nError opening file for writing." << endl;
                    }
                }            
                break;
            }
            case 2: {
                cout << "\n\t\t----- PARKING LOT STATUS -----\n";
                int spotsPerRow = 3;
                int totalSpots = 30;
                int count = 0;

                for (int i = 0; i < totalSpots; i++) {
                    if (lot.isAvailable(i)) {
                        cout << "Spot " << i + 1 << ": Available\t"; 
                    } else {
                        cout << "Spot " << i + 1 << ": Occupied\t";
                    }

                    count++;

                    if (count % spotsPerRow == 0) {
                        cout << endl;
                    }
                }

                if (count % spotsPerRow != 0) {
                    cout << endl;
                }

                cout << "-------------------------------\n";
                break;
            }

            case 3: {
                int spotToRemove;
                cout << "Enter the parking spot number to remove the customer from (1-30): ";
                cin >> spotToRemove;

                spotToRemove -= 1;

                if (spotToRemove < 0 || spotToRemove >= 30) {
                    cout << "Invalid spot number. Please enter a number between 1 and 30." << endl;
                } else {
                    lot.releaseSpot(spotToRemove);
                    cout << "Customer removed from parking spot: " << spotToRemove + 1 << endl;
        
                    lot.updateFile("parking_lot_info.txt");
                }
                break;
            }

            case 4: {
                ifstream file("parking_lot_info.txt");
                if (file.is_open()) {
                    string line;
                    int customerNumber = 1;
                    bool isCustomer = false;

                    cout << "\n----- VIEW ALL CUSTOMERS -----\n";

                    while (getline(file, line)) {
                        if (line == "Customer:") {
                            if (isCustomer) {
                                cout << "-----------------------\n";
                            }
                            isCustomer = true;
                            cout << "\nCUSTOMER #" << customerNumber++ << ":\n";
                        }
                        cout << line << endl;
                    }

                    if (isCustomer) {
                        cout << "-----------------------\n";
                    }
                    file.close();
                } else {
                    cerr << "Error opening file for reading." << endl;
                }
                break;
            }
            case 5:
                cout << "Program ended." << endl;
                break;
        }
    } while (userInput != 5);

    return 0;
}
