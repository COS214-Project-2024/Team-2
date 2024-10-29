#ifndef ECONOMIC_H
#define ECONOMIC_H

#include <iostream>

#include "CityGrowth.h"

class Economic : public CityGrowth
{
    private:
        int size = 0;
    
    public:
        bool grow() override
        {
            size ++;

            if(size % 50 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        };
        bool shrink() override
        {
            if(size == 0)
            {
                std::cout << "City economic already at 0" << std::endl;
                return false;
            }

            size--;

            if(size % 50 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        };
        int get() const override
        {
            return size;
        };
};

#endif