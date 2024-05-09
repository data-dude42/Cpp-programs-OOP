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

#ifndef SENECA_ICECREAM_H
#define SENECA_ICECREAM_H

namespace seneca
{
    class Icecream
    {
        char vanilla_cone{};
        int flavour_num{};
        int scoops{};
    
    public:
        void getOrder();
        void printOrder();
        double tot_amount{};
    };
}

#endif