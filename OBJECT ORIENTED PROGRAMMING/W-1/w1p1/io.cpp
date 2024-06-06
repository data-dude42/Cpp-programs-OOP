

#include <iostream>
#include "io.h"
using namespace std;

// PRINTS THE int VALUE IN WIDTH OF FIELDWIDTH...
namespace seneca {
    void printInt(int value, int fieldWidth) {
        cout << value;
        for (int i = 0; i < fieldWidth - intDigits(value); i++) {
            cout << " ";
        }
    }
    
    // RETURNS number OF DIGITS IN AN INTEGER...
    int intDigits(int value) {
        int count = (value == 0);
        while (value != 0) {
            value /= 10;
            ++count;
        }
        return count;
    }

    // PERFORMS A FOOL-PROFF INTEGER ENTRY...
    int getInt(int min, int max) {
        int val = min - 1;
        bool done = false;
        while (!done) {
            cin >> val;
            if (val < min || val > max) {
                cout << "Invalid value!" << endl << "The value must be between " << min << " and " << max << ": ";
            }
            else {
                done = true;
            }
        }
        return val;
    }

    // MOVES THE CURSOR BACKWARDS...
    void goBack(int n) {
        for (int i = 0; i < n; cout << "\b", i++);
    }

    // DISPLAYS THE "UI" MENU...
    int menu(int noOfSamples) {
        line(28);
        cout << "| No Of Samples: ";
        printInt(noOfSamples, 5);
        cout << "     |" << endl;
        line(28);
        cout << "| 1- Set Number of Samples |" << endl;
        cout << "| 2- Enter Samples         |" << endl;
        cout << "| 3- Graphs                |" << endl;
        cout << "| 0- Exit                  |" << endl;
        cout << "\\ >                        /";
        goBack(24);

        return getInt(0, 3);
    }

    // DRAW THE LINE...
    void labelLine(int n, const char* label) {
        cout << "+";
        for (int i = 0; i < n - 2; cout << "-", i++);
        cout << "+";
        if (label) {
            goBack(n - 4);
            cout << label;
        }
        cout << endl;
    }
    void line(int n) {
        cout << "+";
        for (int i = 0; i < n - 2; cout << "-", i++);
        cout << "+";
        cout << endl;
    }
}
