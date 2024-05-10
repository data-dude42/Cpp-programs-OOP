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

#ifndef SENECA_VENDOR_H
#define SENECA_VENDOR_H
#include "Icecream.h"

namespace seneca
{
    class Vendor
    {
        Icecream *icecream{};
        int num_icecream{};
        double final_price{};
        double tax{};
        double bill_amt{};
        void printLogo();

    public:
        void setEmpty();
        void takeOrders();
        void displayOrders();
        void clearData();
    };
}
#endif // SENECA_VENDOR_H