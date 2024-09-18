#include "connection.h"

using namespace std;

int main()
{
    int userInput;

    do {
        cout << "Choose an integer 1-5 to take action. " << endl;
        cout << "1.) Would you like to add a customer? " << endl;
        cout << "2.) Print parking lot status. " << endl;
        cout << "3.) Would you like to remove a customer? " << endl;
        cout << "4.) View all customer in the paring lot. " << endl;
        cout << "5.) Would you like to end the program? " << endl;

        cin >> userInput;

        if(userInput < 1 || userInput > 5) {
            cout << "\n\nChoose an integer 1-5 please. " << endl << endl;
        }
    } while(userInput < 1 || userInput > 5);


    return 0;
}