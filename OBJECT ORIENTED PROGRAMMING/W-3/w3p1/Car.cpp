
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Car.h"
using namespace std;

namespace seneca
{
    // Member function to check if the object is in a safe recognizable empty state.
    bool Car::isEmpty() const
    {
        bool retVal = false;
        if (m_makeModel == nullptr || m_makeModel[0] == '\0' || m_serviceDesc == nullptr || m_serviceDesc[0] == '\0')
        {
            retVal = true;
        }
        return retVal;
    }

    // Member function sets the object a safe recognizable empty state.
    void Car::setEmpty()
    {
        m_licencePlate[0] = {};
        m_makeModel = {};
        m_serviceDesc = {};
        m_cost = 0.0;
    }

    /* Member function to deallocate dynamically allocated memory for
       "make and model" and "service description" member variables. */
    void Car::deallocateMemory()
    {
        delete[] m_makeModel;
        delete[] m_serviceDesc;
        m_makeModel = m_serviceDesc = nullptr;
    }

        void Car::set(const char plateNo[], const char *carMakeModel, const char *serviceDesc, double serviceCost)
    {
        deallocateMemory();
        if (carMakeModel != nullptr && serviceDesc != nullptr && plateNo[0])
        {
            strcpy(m_licencePlate, plateNo);
            m_makeModel = new char[strlen(carMakeModel) + 1];
            strcpy(m_makeModel, carMakeModel);
            m_serviceDesc = new char[strlen(serviceDesc) + 1];
            strcpy(m_serviceDesc, serviceDesc);
            m_cost = serviceCost;
        }
    }

    void Car::display() const
    {
        if (!isEmpty())
        {
            cout.width(15);
            cout.setf(ios::left);
            cout << "License Plate:";

            cout.unsetf(ios::left);

            cout.width(20);
            cout.setf(ios::right);
            cout << m_licencePlate << endl;
            cout.unsetf(ios::right);

            cout.width(15);
            cout.setf(ios::left);
            cout << "Model:";

            cout.unsetf(ios::left);

            cout.width(20);
            cout.setf(ios::right);
            cout << m_makeModel << endl;

            cout.unsetf(ios::right);

            cout.width(15);
            cout.setf(ios::left);
            cout << "Service Name:";

            cout.unsetf(ios::right);

            cout.width(20);
            cout.setf(ios::right);
            cout << m_serviceDesc << endl;

            cout.unsetf(ios::right);

            cout.width(15);
            cout.setf(ios::left);
            cout << "Service Cost:";

            cout.unsetf(ios::right);

            cout.width(20);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << m_cost << endl;

            cout.unsetf(ios::right);
        }
    }
}
