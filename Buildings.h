#ifndef BUILDINGS_H
#define BUILDINGS_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;

/**
 * @brief Represents a building component in a structure hierarchy.
 * 
 * The Buildings class serves as a base class for different types of building structures.
 * It provides virtual methods that can be overridden in derived classes, allowing for
 * adding and removing components, retrieving and setting prices, and checking occupancy status.
 */
class Buildings {
    public:
        /**
         * @brief Adds a building component.
         * 
         * @param component Pointer to the Buildings object to add.
         * @throws std::logic_error If the operation is not supported by the derived class.
         */
        virtual void add(Buildings* component);

        /**
         * @brief Removes a building component.
         * 
         * @param component Pointer to the Buildings object to remove.
         * @throws std::logic_error If the operation is not supported by the derived class.
         */
        virtual void remove(Buildings* component);

        /**
         * @brief Gets the type of the building.
         * 
         * @return A string representing the type of the building.
         * @throws std::logic_error If the operation is not supported by the derived class.
         */
        virtual string getType();

        /**
         * @brief Gets the price of the building.
         * 
         * @return The price of the building.
         * @throws std::logic_error If the operation is not supported by the derived class.
         */
        virtual int getPrice();

        /**
         * @brief Sets the price of the building.
         * 
         * @param p The price to set for the building.
         * @throws std::logic_error If the operation is not supported by the derived class.
         */
        virtual void setPrice(int p);

        /**
         * @brief Checks if the building is occupied.
         * 
         * @return A boolean indicating if the building is occupied.
         * @throws std::logic_error If the operation is not supported by the derived class.
         */
        virtual bool getTaken();

        /**
         * @brief Sets the occupancy status of the building.
         * 
         * @param t The occupancy status to set.
         * @throws std::logic_error If the operation is not supported by the derived class.
         */
        virtual void setTaken(bool t);
};

#endif
