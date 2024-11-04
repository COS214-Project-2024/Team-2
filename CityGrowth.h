#ifndef CITYGROWTH_H
#define CITYGROWTH_H

/**
 * @class CityGrowth
 * @brief Abstract base class for managing city growth.
 * 
 * This class serves as an interface for handling the growth and 
 * shrinkage of a city. Derived classes must implement the 
 * functionalities for growing and shrinking the city's size.
 */
class CityGrowth
{
    private:
        int size = 0; ///< The current size of the city.
    
    public:
        /**
         * @brief Increases the size of the city.
         * 
         * This pure virtual method must be implemented by derived 
         * classes to define how the city grows.
         * 
         * @return true if the city growth was successful, false otherwise.
         */
        virtual bool grow() = 0;

        /**
         * @brief Decreases the size of the city.
         * 
         * This pure virtual method must be implemented by derived 
         * classes to define how the city shrinks.
         * 
         * @return true if the city shrinkage was successful, false otherwise.
         */
        virtual bool shrink() = 0;

        /**
         * @brief Retrieves the current size of the city.
         * 
         * This pure virtual method must be implemented by derived 
         * classes to return the current size of the city.
         * 
         * @return The current size of the city.
         */
        virtual int get() const = 0;
};

#endif
