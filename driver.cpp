#include "car.h"
#include "customer.h"
#include "driver.h"

using namespace std;

int main() {
    int userInput;

    do {
        asciiArt();
        cout << "Choose an integer 1-5 to take action. " << endl;
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
            string make, model, licensePlate, color, name, gender, age;

            cout << "Enter the car's make: ";
            cin >> make;
            cout << "Enter the car's model: ";
            cin >> model;
            cout << "Enter the car's license plate: ";
            cin >> licensePlate;
            cout << "Enter the car's color: ";
            cin >> color;
            //New variables for customer functions, may be moved later
            cout << "Enter the customer's name: ";
            cin >> name;
            cout << "Enter the customer's gender: ";
            cin >> gender;
            cout << "Enter the customer's age: ";
            cin >> age;

            // Create a new Car object with the provided information
            Car newCar(make, model, licensePlate, color);

            // Display the car details
            cout << "Customer added with car details: " << newCar.getDetails() << endl;
            
            //Ties together Car info and Customer info, displays customer info.
            Customer getInfo();
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

    void asciiArt() {
            int max = 4;
        int min = 1;

        if (max < min) {
            swap(max, min);
        }

        srand(time(0));
        int randNum = rand()%(max-min + 1) + min;
        cout << randNum;

        if(randNum == 1) {
            cout << "        ____                      _____________              _____________" << endl;
            cout << "   ____//_]|________         ____//__][__][___|         ____//__][______||" <<  endl;
            cout << "  (o _ |  -|   _  o|        (o  _|  -|     _ o|        (o _ |  -|   _   o|" << endl;
            cout << "   `(_)-------(_)--'         `-(_)--------(_)-'         `(_)-------(_)---'" << endl;
        }

        else if(randNum == 2) {
            cout << "                                                         _________________________    " << endl;
            cout << "                    /\\\\      _____          _____       |   |     |     |    | |  \\  " << endl;
            cout << "     ,-----,       /  \\\\____/__|__\\_    ___/__|__\\___   |___|_____|_____|____|_|___\\ " << endl;
            cout << "  ,--'---:---`--, /  |  _     |     `| |      |      `| |                    | |    \\" << endl;
            cout << " ==(o)-----(o)==J    `(o)-------(o)=   `(o)------(o)'   `--(o)(o)--------------(o)--' " << endl;
        }

        else if(randNum == 3) {
            cout << "                                  @" << endl;
            cout << "               (__)    (__) _____/" << endl;
            cout << "            /| (oo) _  (oo)/----/_____    *" << endl;
            cout << "  _o\\______/_|\\_\\/_/_|__\\/|____|//////== *- *  * -" << endl;
            cout << " /_________   \\   00 |   00 |       /== -* * -" << endl;
            cout << "[_____/^^\\_____\\_____|_____/^^\\_____]     *- * -" << endl;
            cout << "      \\__/                 \\__/" << endl;
        }

        else {
            cout << "                       ____________________" << endl;
            cout << "                     //|           |        \\" << endl;
            cout << "                   //  |           |          \\" << endl;
            cout << "      ___________//____|___________|__________()\\__________________" << endl;
            cout << "    /__________________|_=_________|_=___________|_________________{}" << endl;
            cout << "    [           ______ |           | .           | ==  ______      { }" << endl;
            cout << "  __[__        /##  ##\\|           |             |    /##  ##\\    _{# }_" << endl;
            cout << " {_____)______|##    ##|___________|_____________|___|##    ##|__(______}" << endl;
            cout << "             /  ##__##                              /  ##__##        \\" << endl;
            cout << "----------------------------------------------------------------------------" << endl;
        }
    }
    return 0;
}
