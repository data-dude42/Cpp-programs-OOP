/*///////////////////////////////////////////////////////////////////////
                        Workshop-3 Part-2
Full Name  : PARAS SINGH
Student ID#: 165114232
Email      : psingh721@myseneca.ca
Section    : ZEE
Date       : 07-FEB-2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "Utils.h"
#include <stdlib.h> // including the built-in library because size_t is a function of this library
#include <stddef.h>
using namespace std;
namespace seneca
{
    Utils ut;
    int Utils::getInt()
    {
        int val{};
        cin >> val;
        while (cin.fail())
        {
            cout << "Invalid entry, retry" << endl << "> ";
            cin.clear();
            cin.ignore(12000, '\n');
            cin >> val;
        }
        cin.ignore(12000, '\n'); // only one character will be ignored......
        return val;
    }

    void Utils::getCstr(char *str, size_t len)
    {
        cin.getline(str, len + 1);
        while (cin.fail())
        {
            cout << "Maximum " << len << " chars!, retry\n ";
            cin.clear();
            cin.ignore(12000, '\n');
            cin.getline(str, len + 1);
        }
    }

    bool Utils::yes()
    {
        char response{};
        char newline{ };
        cin.get(response);
        cin.get(newline);
        while (newline != '\n' ||
               (response != 'Y' && response != 'y' && response != 'N' && response != 'n'))
        {
            cout << "Only Y or N are acceptable:" << endl << "> ";
            if (newline != '\n')
                cin.ignore(10000, '\n');
            cin.get(response).get(newline);
        }
        return response == 'Y' || response == 'y';
    }
}
