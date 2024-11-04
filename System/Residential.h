#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Buildings.h"

using namespace std;

/**
 * @brief Class representing residential buildings in the city.
 * 
 * The Residential class is derived from the Buildings class and defines
 * different types of residential buildings, their prices, and satisfaction
 * rates.
 */
class Residential : public Buildings
{
    private:
        string type[3] = {"houses", "apartments", "estates"}; ///< Types of residential buildings.
        int price[3] = {200, 100, 250}; ///< Prices for the respective types of residential buildings.
        int position; ///< Index representing the current type of building.
        int satisfactionRate = 1; ///< Satisfaction rate of the residential buildings.
        string myType = "residential"; ///< Type of the building category.
        bool taken = false; ///< Flag indicating if the building type is taken.

    public:
        /**
         * @brief Constructs a Residential object of a specified type.
         * 
         * @param type The type of residential building to create.
         */
        Residential(string type);

        /**
         * @brief Retrieves the type of the residential building.
         * 
         * @return A string representing the type of building.
         */
        std::string getType();

        /**
         * @brief Retrieves the price of the residential building.
         * 
         * @return The price of the building.
         */
        int getPrice();

        /**
         * @brief Retrieves the position/index of the building type.
         * 
         * @return The position of the building type in the array.
         */
        int getPosition();

        /**
         * @brief Retrieves the satisfaction rate of the residential building.
         * 
         * @return The satisfaction rate.
         */
        int getSatisfaction();

        /**
         * @brief Sets the price of the residential building.
         * 
         * @param p The new price to set for the building.
         */
        void setPrice(int p);

        /**
         * @brief Checks if the residential building type is taken.
         * 
         * @return True if the building type is taken, false otherwise.
         */
        bool getTaken();

        /**
         * @brief Sets the taken status of the residential building type.
         * 
         * @param t The new taken status to set.
         */
        void setTaken(bool t);
};

#endif
