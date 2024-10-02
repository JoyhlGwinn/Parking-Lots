#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <cstdlib>  
#include <ctime>

using namespace std;

void parkingSpotPicker(){
    int numGen(int max, int min) {
        if (max < min) {
        swap(max, min);
    }
    srand(time(0));
    int randNum = rand()%(max-min + 1) + min;

    return randNum;
    }
    int spotPicker() {
        int max = 64;
        int min = 1;
        int randNum = numGen(max, min);
        cout << "Your parking spot number is " << randNum << endl;
    }
}
void asciiArt(){
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


#endif
