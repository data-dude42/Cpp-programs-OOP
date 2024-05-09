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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Customer.h"
using namespace std;

namespace seneca
{
    // This query method checks if the object is in a safe empty state.
    bool Customer::isEmpty() const
    {
        bool retVal = false;
        if (m_name == nullptr || m_name[0] == '\0' || m_car == nullptr)
        {
            retVal = true;
        }
        return retVal;
    }

    const Car &Customer::car() const
    {
        return *m_car;
    }

    // This method sets the customer to a safe empty state.
    void Customer::setEmpty()
    {
        m_id = 0;
        m_name = nullptr;
        m_car = nullptr;
    }

    // This Member function deallocates the dynamically allocated memory
    void Customer::deallocateMemory()
    {
        delete[] m_name;
    }

    void Customer::set(int customerId, const char *name, const Car *car)
    {
        deallocateMemory();
        if (name != nullptr && name[0] != '\0' && car != nullptr)
        {
            m_id = customerId;
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
            m_car = car;
        }
    }

    void Customer::display() const
    {
        if (!isEmpty())
        {
            cout.width(15);       //  next print will be in 15 spaces
            cout.setf(ios::left); // setting left alignment
            cout << "Customer ID:";
            cout.unsetf(ios::left); // unsetting left alignment

            cout.width(20);
            cout.setf(ios::right);
            cout << m_id << endl;
            cout.unsetf(ios::right);

            cout.width(15);
            cout.setf(ios::left);
            cout << "First Name:";
            cout.unsetf(ios::left);

            cout.width(20);
            cout.setf(ios::right);
            cout << m_name << endl;
            cout.unsetf(ios::right);

            m_car->display();
        }
    }
}