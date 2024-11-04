#ifndef ECONOMIC_H
#define ECONOMIC_H

#include <iostream>

#include "CityGrowth.h"

/**
 * @brief Class representing the economic growth of a city.
 * 
 * Inherits from the CityGrowth class and provides methods to grow and shrink
 * the economic size of the city.
 */
class Economic : public CityGrowth
{
    private:
        int size = 0; ///< Current economic size of the city.
    
    public:
    /**
         * @brief Increases the economic size of the city.
         * 
         * Increments the size by 1 and determines if the city has reached
         * an even size. Returns true if the new size is even, otherwise false.
         * 
         * @return true if the size is even after growth, otherwise false.
         */
        bool grow() override
        {
            size ++; // Increment economic size

            if(size % 2 == 0) // Return true if size is even, false otherwise
            {
                return true;
            }
            else
            {
                return false;
            }
        };

        /**
         * @brief Decreases the economic size of the city.
         * 
         * Decrements the size by 1 if it is greater than 0. Provides a 
         * message if the economic size is already at 0. Determines if the 
         * city has reached an even size after shrinking. Returns true if 
         * the new size is even, otherwise false.
         * 
         * @return true if the size is even after shrinking, otherwise false.
         */
        bool shrink() override
        {
            if(size == 0)
            {
                std::cout << "City economic already at 0" << std::endl;
                return false; // Cannot shrink below 0
            }

            size--; // Decrement economic size

            if(size % 2 == 0) // Return true if size is even, false otherwise
            {
                return true;
            }
            else
            {
                return false;
            }
        };

        /**
         * @brief Retrieves the current economic size of the city.
         * 
         * @return The current size of the city's economy.
         */
        int get() const override
        {
            return size;
        };
};

#endif