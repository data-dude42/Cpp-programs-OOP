/*///////////////////////////////////////////////////////////////////////
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

#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
#include <stdlib.h>
#include <stddef.h>
namespace seneca
{
    struct Utils
    {
        int getInt();
        void getCstr(char *str, size_t len);
        bool yes();
    };
    extern Utils ut;
}
#endif //! SENECA_UTILS_H