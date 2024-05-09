/*/////////////////////////////////////////////////////////////////////////
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
#include <cstring>
#include "Utils.h"    // including headers as well
#include "Icecream.h" // including headers as well
#include <stdlib.h>
#include <stddef.h>

using namespace std;
namespace seneca
{
    void Icecream::getOrder()
    {
        flavour_num = 1, scoops = 1;

        // prompting for choosing a flavour
        cout << "Select flavour:" << endl;
        cout << "----------------" << endl;
        cout << "1: Chocolate\n2: Strawberry\n3: Mango\n4: Tutti fruit\n5: Almond crunch" << endl;
        cout << "----------------" << endl;
        cout << "> ";

        // Validating inputs
        do
        {
            if (flavour_num < 1 || flavour_num > 5)
            {
                cout << "Invlid value(1<=val<=5)\n> ";
            }
            flavour_num = ut.getInt();
        } while (flavour_num < 1 || flavour_num > 5);

        // Prompt for entering the total number of scoops
        cout << "Number of Scoops (max 3)\n> ";

        // Validating inputs
        do
        {
            if (scoops < 1 || scoops > 3)
            {
                cout << "Invlid value(1<=val<=3)\n> ";
            }
            // Calling the getInt() utility function for an integer input validation
            scoops = ut.getInt();
        } while (scoops < 1 || scoops > 3);

        // Prompt for user to enter (Y)es if they want a Vanilla Wafer else (N)o
        cout << "Vanilla wafer cone?" << endl;
        cout << "(Y)es/(N)o > ";
        vanilla_cone = ut.yes();
    }

    void Icecream::printOrder()
    {
        const double scoop_price = 5;
        double p_scoop = 0.0, p_choc = 0.0, p_vanilla = 0.0;
        p_vanilla = vanilla_cone ? 5 : 0; // if result is true then 5 else 0.....

        cout.width(14);
        cout << "Order details:";
        cout.width(21);
        cout.setf(ios::right);
        cout << "Price" << endl;

        cout.unsetf(ios::right);

        cout << "-----------------------------------" << endl;

        cout << "Number of scoops, " << scoops << " total:";

        cout.width(9);
        cout.setf(ios::fixed);
        cout.precision(2);

        p_scoop += scoop_price * scoops;

        cout << p_scoop << endl;

        switch (flavour_num)
        {
        case 1:
            cout.width(26);
            cout.setf(ios::left);
            cout << "Chocolate flavour:";

            cout.unsetf(ios::left);

            cout.width(9);
            cout.setf(ios::fixed);
            cout.precision(2);

            p_choc = scoops;
            cout << p_choc << endl;
            break;

        case 2:
            cout << "Strawberry flavour" << endl;
            break;

        case 3:
            cout << "Mango flavour" << endl;
            break;

        case 4:
            cout << "Tutti fruit flavour" << endl;
            break;

        case 5:
            cout << "Almond crunch flavour" << endl;
            break;
        }
        cout.width(26);
        cout.setf(ios::left);
        cout << "Vanilla Wafer:";

        cout.unsetf(ios::left);

        cout.width(9);
        cout.setf(ios::fixed);
        cout.precision(2);
        if (p_vanilla)
        {
            cout << scoop_price << endl;
        }
        else
        {
            cout << "0.00" << endl;
        }
        tot_amount = p_scoop + p_choc + p_vanilla;

        cout.width(26);
        cout.setf(ios::left);
        cout << "Price:";

        cout.unsetf(ios::left);

        cout.width(9);
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << tot_amount << endl;
    }

}
