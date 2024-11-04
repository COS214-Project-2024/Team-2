#ifndef Commercial_h
#define Commercial_h

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Buildings.h"

using namespace std;

/**
 * @class Commercial
 * @brief Represents commercial buildings in the city.
 * 
 * This class defines commercial buildings such as shops, offices, and malls.
 * It provides methods to get the type, price, and satisfaction rate of the building.
 */
class Commercial : public Buildings
{
    private:
        string type[3] = {"shops", "offices", "malls"}; ///< Types of commercial buildings.
        int price[3] = {350, 100, 450}; ///< Prices corresponding to each type.
        int position; ///< The index of the building type.
        int satisfactionRate = 1; ///< Satisfaction rate of the building.
        string myType = "commercial"; ///< Type identifier for the building.
        bool taken = false; ///< Indicates whether the building is occupied.

    public:
        /**
         * @brief Constructs a Commercial object with the specified type.
         * 
         * @param t The type of the commercial building (e.g., "shops", "offices", "malls").
         */
        Commercial(string type);

        /**
         * @brief Gets the type of the commercial building.
         * 
         * @return A string representing the type of the building.
         */
        std::string getType();

        /**
         * @brief Gets the price of the commercial building.
         * 
         * @return The price of the building as an integer.
         */
        int getPrice();

        /**
         * @brief Gets the position of the commercial building in the type array.
         * 
         * @return An integer representing the position.
         */
        int getPosition();

        /**
         * @brief Gets the satisfaction rate of the commercial building.
         * 
         * @return The satisfaction rate as an integer.
         */
        int getSatisfaction();

        /**
         * @brief Sets the price of the commercial building.
         * 
         * @param p The new price to set for the building.
         */
        void setPrice(int p);

        /**
         * @brief Checks if the commercial building is occupied.
         * 
         * @return true if the building is occupied, false otherwise.
         */
        bool getTaken();

        /**
         * @brief Sets the occupancy status of the commercial building.
         * 
         * @param t A boolean indicating whether the building is occupied (true) or not (false).
         */
        void setTaken(bool t);
};

#endif
