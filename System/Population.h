#ifndef POPULATION_H
#define POPULATION_H

#include <iostream>

#include "CityGrowth.h"

/**
 * @brief Represents the population of a city and its growth dynamics.
 * 
 * The Population class inherits from the CityGrowth class and implements
 * methods to grow and shrink the city's population. It maintains the current
 * size of the population and provides functionality to check the size.
 */
class Population : public CityGrowth
{
    private:
        int size = 0; ///< Current population size.
    
    public:
        /**
         * @brief Increases the population size by one.
         * 
         * This method increments the population size and determines whether
         * the population is now at an even number.
         * 
         * @return true if the new size is even, false otherwise.
         */
        bool grow() override
        {
            size ++;

            if(size % 2 == 0)
            {
                return true;
            }
            // if(size == 2)
            // {
            //     return true;
            // }
            else
            {
                return false;
            }
        };

        /**
         * @brief Decreases the population size by one.
         * 
         * This method decrements the population size if it is greater than zero.
         * If the population is already at zero, it outputs a message indicating
         * this and does not change the size.
         * 
         * @return true if the new size is even after shrinking, false otherwise.
         */
        bool shrink() override
        {
            if(size == 0)
            {
                std::cout << "City population already at 0" << std::endl;
                return false;
            }

            size--;

            if(size % 2 == 0)
            {
                return true;
            }
            // if(size == 2)
            // {
            //     return true;
            // }
            else
            {
                return false;
            }
        };

        /**
         * @brief Gets the current population size.
         * 
         * @return The current size of the population.
         */
        int get() const override
        {
            return size;
        };
};

#endif