#include "parkingLot.h"

// Constructor
ParkingLot::ParkingLot(int capacity) 
    : lotCapacity(capacity), currentOccupancy(0) {
    parkedCars = new Car*[capacity](); // Initializes all pointers to nullptr
}

// Destructor
ParkingLot::~ParkingLot() {
    for (int i = 0; i < lotCapacity; ++i) {
        delete parkedCars[i]; // Safe to delete since we check for nullptr
    }
    delete[] parkedCars;
}

// Check if a spot is available
bool ParkingLot::isAvailable(int spot) {
    return spot >= 0 && spot < lotCapacity && parkedCars[spot] == nullptr;
}

// Assign a car to a parking spot
void ParkingLot::assignCar(int spot, Car* car) {
    if (spot < 0 || spot >= lotCapacity || !isAvailable(spot)) {
        cout << "Invalid spot or spot already occupied." << endl;
        return;
    }
    parkedCars[spot] = car;
    currentOccupancy++;
}

// Release a parking spot
void ParkingLot::releaseSpot(int spot) {
    if (spot < 0 || spot >= lotCapacity || isAvailable(spot)) {
        cout << "Invalid spot or spot already empty." << endl;
        return;
    }
    delete parkedCars[spot]; // Safely delete car object
    parkedCars[spot] = nullptr;
    currentOccupancy--;
}

// Display the current status of the parking lot
void ParkingLot::displayStatus() const {
    cout << "Parking Lot Status:" << endl;
    for (int i = 0; i < lotCapacity; ++i) {
        cout << "Spot " << i << ": " 
             << (parkedCars[i] ? "Occupied" : "Available") << endl;
    }
}

// Save parking lot data to a file
void ParkingLot::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    file << lotCapacity << " " << currentOccupancy << endl;
    for (int i = 0; i < lotCapacity; ++i) {
        if (parkedCars[i]) {
            file << i << " "
                 << parkedCars[i]->getMake() << " "
                 << parkedCars[i]->getModel() << " "
                 << parkedCars[i]->getLicensePlate() << " "
                 << parkedCars[i]->getColor() << endl;
        }
    }
}

// Load parking lot data from a file
void ParkingLot::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    int capacity, occupancy;
    file >> capacity >> occupancy;

    if (capacity != lotCapacity) {
        cerr << "Mismatch in lot capacity." << endl;
        return;
    }

    // Clear current state
    for (int i = 0; i < lotCapacity; ++i) {
        delete parkedCars[i]; // Safely delete existing cars
        parkedCars[i] = nullptr;
    }
    currentOccupancy = 0;

    // Load data from file
    int spot;
    string make, model, licensePlate, color;
    while (file >> spot >> make >> model >> licensePlate >> color) {
        if (spot < 0 || spot >= lotCapacity) {
            cerr << "Invalid spot in file." << endl;
            continue;
        }
        parkedCars[spot] = new Car(make, model, licensePlate, color);
        currentOccupancy++;
    }

    file.close();
}
