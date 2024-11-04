#ifndef BUILDINGSUNIT_H
#define BUILDINGSUNIT_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Buildings.h"
#include "./Utilities/Utilities.h"
#include "./Utilities/MaterialFactory.h"
#include "./Utilities/WaterSupply.h"
#include "./Utilities/PowerPlant.h"
#include "Government.h"

using namespace std;

/**
 * @brief Represents a unit of buildings within a city that is governed by a central authority.
 * 
 * BuildingsUnit provides methods to manage a collection of buildings, including adding, removing,
 * retrieving specific buildings, and managing utilities. It interacts with the Government class
 * to ensure the construction and modification of buildings are within the city's budget.
 */
class BuildingsUnit : public Buildings {
    private:
        /**
         * @brief A vector of building components that are part of this unit.
         */
        std::vector<Buildings*> children;

        /**
         * @brief Pointer to the Government instance that oversees this unit.
         */
        Government* govern;

        /**
         * @brief Pointer to the Utilities instance managing resources for the unit.
         */
        Utilities* utilities;

    public:
        /**
         * @brief Constructs a BuildingsUnit with a specified Government authority.
         * 
         * @param g Pointer to the Government instance managing this BuildingsUnit.
         */
        BuildingsUnit(Government* g);

        /**
         * @brief Adds a building component to the unit if funds are sufficient.
         * 
         * @param comp Pointer to the Buildings object to add.
         */
        void add(Buildings* comp);

        /**
         * @brief Removes a building component at a specified index.
         * 
         * @param index Index of the building component to remove from the unit.
         */
        void remove(int index);

        /**
         * @brief Retrieves a child building component at a specified index.
         * 
         * @param index Index of the building component to retrieve.
         * @return Pointer to the Buildings object at the specified index.
         */
        Buildings* getChild(int index);

        /**
         * @brief Deletes all buildings of a specific type within the unit.
         * 
         * @param myType The type of buildings to delete.
         */
        void deleteSpecificTree(string myType);

        /**
         * @brief Calculates and outputs the total price of all buildings of a specific type.
         * 
         * @param myType The type of buildings to calculate the total price for.
         */
        void getTreePrice(string myType);

        /**
         * @brief Sets a new price for all buildings of a specific type.
         * 
         * @param myType The type of buildings to update the price for.
         * @param price The new price to set for each building of this type.
         */
        void setTreePrice(string myType, int price);

        /**
         * @brief Attempts to find an available house within the unit.
         * 
         * @return True if a house was found and marked as occupied, otherwise false.
         */
        bool getHouse();

        /**
         * @brief Attempts to find available employment within the unit.
         * 
         * @return True if employment was found and marked as occupied, otherwise false.
         */
        bool getEmployment();

        /**
         * @brief Requests utilities required for the unit, including materials, water, and power.
         */
        void requestUtilities();

        /**
         * @brief Destructor for BuildingsUnit, deallocates all child building components.
         */
        ~BuildingsUnit();
};

#endif
