
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
