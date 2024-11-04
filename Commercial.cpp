#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Commercial.h"

using namespace std;

/**
 * @brief Constructs a Commercial object with the specified type.
 * 
 * This constructor initializes the Commercial object based on the provided 
 * type of building. It assigns the corresponding position in the type array.
 * 
 * @param t The type of the commercial building (e.g., "shops", "offices", "malls").
 */
Commercial::Commercial(string t)
{
    for(int i = 0; i < 3; i++)
    {
        if(type[i] == t)
        {
            position = i;
        }
    }
}

/**
 * @brief Gets the type of the commercial building.
 * 
 * This method returns the type identifier of the commercial building.
 * 
 * @return A string representing the type of the building.
 */
string Commercial::getType()
{
    return myType;
}

/**
 * @brief Gets the price of the commercial building.
 * 
 * This method retrieves the price of the building based on its position 
 * in the type array.
 * 
 * @return The price of the building as an integer.
 */
int Commercial::getPrice()
{
    return price[position];
}

/**
 * @brief Gets the position of the commercial building in the type array.
 * 
 * This method returns the index of the commercial building's type in the 
 * predefined type array.
 * 
 * @return An integer representing the position.
 */
int Commercial::getPosition()
{
    return position;
}

/**
 * @brief Gets the satisfaction rate of the commercial building.
 * 
 * This method returns the current satisfaction rate of the building.
 * 
 * @return The satisfaction rate as an integer.
 */
int Commercial::getSatisfaction()
{
    return satisfactionRate;
}

/**
 * @brief Sets the price of the commercial building.
 * 
 * This method updates the price of the commercial building based on its 
 * current position in the type array.
 * 
 * @param pric The new price to set for the building.
 */
void Commercial::setPrice(int pric)
{
    price[position] = pric;
}

/**
 * @brief Checks if the commercial building is occupied.
 * 
 * This method returns the occupancy status of the commercial building.
 * 
 * @return true if the building is occupied, false otherwise.
 */
bool Commercial::getTaken()
{
    return taken;
}

/**
 * @brief Sets the occupancy status of the commercial building.
 * 
 * This method updates the occupancy status of the commercial building.
 * 
 * @param tak A boolean indicating whether the building is occupied (true) 
 * or not (false).
 */
void Commercial::setTaken(bool tak)
{
    taken = tak;
}
