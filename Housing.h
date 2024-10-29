#ifndef HOUSING_H
#define HOUSING_H

#include <iostream>

#include "CityGrowth.h"

class Housing : public CityGrowth
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
                std::cout << "City housing already at 0" << std::endl;
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