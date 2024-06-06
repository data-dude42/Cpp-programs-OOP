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
