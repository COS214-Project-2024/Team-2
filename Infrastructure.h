#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H

#include <iostream>
#include "CityGrowth.h"

/**
 * @brief Class representing city infrastructure growth and shrinkage.
 * 
 * This class inherits from CityGrowth and provides methods to manage
 * the growth and shrinkage of city infrastructure, tracking its size.
 */
class Infrastructure : public CityGrowth
{
    private:
        int size = 0; ///< The current size of the infrastructure.

    public:
        /**
         * @brief Increases the size of the infrastructure.
         * 
         * The method increments the size by 1. If the new size is even,
         * the method returns true; otherwise, it returns false.
         * 
         * @return true if the new size is even, false otherwise.
         */
        bool grow() override
        {
            size++;

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
         * @brief Decreases the size of the infrastructure.
         * 
         * This method decrements the size by 1. If the size is already 
         * 0, a message is printed, and the method returns false. If the 
         * new size is even, it returns true; otherwise, it returns false.
         * 
         * @return true if the new size is even, false otherwise.
         */
        bool shrink() override
        {
            if(size == 0)
            {
                std::cout << "City infrastructure already at 0" << std::endl;
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
         * @brief Retrieves the current size of the infrastructure.
         * 
         * @return The current size of the infrastructure as an integer.
         */
        int get() const override
        {
            return size;
        };
};

#endif
