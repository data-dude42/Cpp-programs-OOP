#include <iostream>
#include "Vendor.h"
#include "Icecream.h"

using namespace std;

namespace seneca
{
    void Vendor::setEmpty()
    {
        icecream = nullptr;
    }

    void Vendor::printLogo() // i have used void function to extract the seneca ice cream shop logo
    {
        cout << "Seneca Icecream shop" << endl;
        cout.width(11);
        cout << "@" << endl;
        cout.width(13);
        cout << "(' .)" << endl;
        cout.width(14);
        cout << "(*.`. )" << endl;
        cout.width(13);
        cout << "\\###/" << endl;
        cout.width(12);
        cout << "\\#/" << endl;
        cout.width(11);
        cout << "V" << endl;
    }

    void Vendor::takeOrders()
    {
        printLogo();
        clearData();
        cout << "How many Icecreams?" << endl
             << "> ";
        cin >> num_icecream;
        icecream = new Icecream[num_icecream]; // allocating memory dynamically.....

        for (int i = 0; i < num_icecream; i++)
        {
            cout << "Order number " << i + 1 << ":" << endl;
            icecream[i].getOrder();
        }
        cout << endl;
    }
    void Vendor::displayOrders()
    {
        cout << "********** Order Summary **********" << endl;

        for (int i = 0; i < num_icecream; i++)
        {
            cout << "Order No: " << i + 1 << ":" << endl;
            icecream[i].printOrder();
            final_price += icecream[i].tot_amount;

            if (i != num_icecream - 1)
            {
                cout << endl;
            }
        }
        cout << "-----------------------------------" << endl;

        cout.width(26);
        cout.setf(ios::left);
        cout << "Price:";

        cout.unsetf(ios::left);

        cout.width(9);
        cout.setf(ios::fixed);
        cout.precision(2);

        cout << final_price << endl;

        tax = final_price * 0.13;

        cout.width(26);
        cout.setf(ios::left);
        cout << "Tax:";

        cout.unsetf(ios::left);

        cout.width(9);
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << tax << endl;

        bill_amt = tax + final_price;

        cout.width(26);
        cout.setf(ios::left);
        cout << "Total Price ($):";

        cout.unsetf(ios::left);

        cout.width(9);
        cout.setf(ios::fixed);
        cout.precision(2);

        cout << bill_amt << endl;
    }

    void Vendor::clearData()
    {
        delete[] icecream;
        icecream = nullptr;
    }

}
