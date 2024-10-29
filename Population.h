#ifndef POPULATION_H
#define POPULATION_H

#include <iostream>

#include "CityGrowth.h"

class Population : public CityGrowth
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
                std::cout << "City population already at 0" << std::endl;
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