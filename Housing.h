#ifndef HOUSING_H
#define HOUSING_H

#include <iostream>

#include "CityGrowth.h"

/**
 * @brief Represents the housing component of city growth.
 * 
 * This class is responsible for managing the size of housing in the city, 
 * allowing for growth and shrinkage based on specific rules. It inherits 
 * from the CityGrowth base class.
 */
class Housing : public CityGrowth
{
    private:
        int size = 0;///< The current size of housing in the city.
    
    public:
    /**
         * @brief Increases the size of housing.
         * 
         * The size is incremented by 1. Returns true if the new size is 
         * even, false if it is odd.
         * 
         * @return true if the new size is even, false if it is odd.
         */
        bool grow() override
        {
            size ++;

            if(size % 2 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        };

        /**
         * @brief Decreases the size of housing.
         * 
         * If the size is already 0, prints a message and returns false. 
         * Otherwise, the size is decremented by 1. Returns true if the 
         * new size is even, false if it is odd.
         * 
         * @return true if the new size is even after shrinking, 
         *         false if it is odd, or if the size was already 0.
         */
        bool shrink() override
        {
            if(size == 0)
            {
                std::cout << "City housing already at 0" << std::endl;
                return false;
            }

            size--;

            if(size % 2 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        };

        /**
         * @brief Gets the current size of housing.
         * 
         * @return The current size of housing.
         */
        int get() const override
        {
            return size;
        };
};

#endif