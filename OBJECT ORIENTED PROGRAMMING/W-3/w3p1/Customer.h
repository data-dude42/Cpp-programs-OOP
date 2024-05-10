/*/////////////////////////////////////////////////////////////////////////
                        Workshop-3 Part-1
Full Name  : PARAS SINGH
Student ID#: 165114232
Email      : psingh721@myseneca.ca
Section    : ZEE
Date       : 04-FEB-2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_CUSTOMER_H
#define SENECA_CUSTOMER_H
#include "Car.h"

namespace seneca
{
    class Customer
    {
        int m_id;
        char *m_name;
        const Car *m_car;

    public:
        const Car &car() const;
        bool isEmpty() const;
        void setEmpty();
        void deallocateMemory();
        void set(int customerId, const char *name, const Car *car);
        void display() const;
    };
}
#endif