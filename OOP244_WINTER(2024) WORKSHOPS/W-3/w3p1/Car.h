/*/////////////////////////////////////////////////////////////////////////
                        Workshop-3 Part-1
Full Name  : PARAS SINGH
Student ID#: 165114232
Email      : psingh721@myseneca.ca
Section    : ZEE
Date       : 04-FEb-2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_CAR_H
#define SENECA_CAR_H

namespace seneca
{
    class Car
    {
        char m_licencePlate[8];
        char *m_makeModel;
        char *m_serviceDesc;
        double m_cost;

    public:
        bool isEmpty() const;
        void setEmpty();
        void deallocateMemory();
        void set(const char plateNo[], const char *carMakeModel, const char *serviceDesc, double serviceCost);
        void display() const;
    };
}
#endif