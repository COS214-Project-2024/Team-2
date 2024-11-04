#ifndef Industrial_h
#define Industrial_h

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Buildings.h"

using namespace std;

/**
 * @brief Represents an industrial building in the city.
 * 
 * This class provides functionality to manage industrial buildings, 
 * including their type, price, position, satisfaction rate, and 
 * whether they are occupied.
 */
class Industrial : public Buildings
{
    private:
        string type[3] = {"factories", "warehouses", "plants"}; ///< The types of industrial buildings.
        int price[3] = {500, 450, 400}; ///< The prices of the industrial buildings.
        int position; ///< The position of the industrial building.
        int satisfactionRate = 2; ///< The satisfaction rate of the industrial building.
        string myType = "industrial"; ///< The type of the industrial building.
        bool taken = false; ///< The occupancy status of the industrial building.

    public:
        /**
         * @brief Constructs an Industrial object with the specified type.
         * 
         * @param type The type of the industrial building (e.g., factories, warehouses, or plants).
         */
        Industrial(string type);

        /**
         * @brief Retrieves the type of the industrial building.
         * 
         * @return The type of the industrial building as a string.
         */
        std::string getType();

        /**
         * @brief Retrieves the price of the industrial building.
         * 
         * @return The price of the industrial building as an integer.
         */
        int getPrice();

        /**
         * @brief Retrieves the position of the industrial building.
         * 
         * @return The position of the industrial building as an integer.
         */
        int getPosition();

        /**
         * @brief Retrieves the satisfaction rate of the industrial building.
         * 
         * @return The satisfaction rate as an integer.
         */
        int getSatisfaction();

        /**
         * @brief Sets the price of the industrial building.
         * 
         * @param p The new price to be set for the industrial building.
         */
        void setPrice(int p);

        /**
         * @brief Checks if the industrial building is taken.
         * 
         * @return True if the building is taken, otherwise false.
         */
        bool getTaken();

        /**
         * @brief Sets the occupancy status of the industrial building.
         * 
         * @param t The new occupancy status (true for taken, false for available).
         */
        void setTaken(bool t);
};

#endif