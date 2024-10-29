#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H

#include <iostream>

#include "CityGrowth.h"

class Infrastructure : public CityGrowth
{
    private:
        int size = 0;
    
    public:
        bool grow() 
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
        bool shrink()
        {
            if(size == 0)
            {
                std::cout << "City infrastructure already at 0" << std::endl;
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
        int get() const
        {
            return size;
        };
};

#endif