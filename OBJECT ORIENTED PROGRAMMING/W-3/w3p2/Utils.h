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
