
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
