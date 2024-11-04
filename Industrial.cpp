#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Industrial.h"

using namespace std;

/**
 * @brief Constructs an Industrial object with the specified type.
 * 
 * This constructor initializes the industrial building based on the given 
 * type, determining its position in the type array.
 * 
 * @param t The type of the industrial building (e.g., factories, warehouses, or plants).
 */
Industrial::Industrial(string t)
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
 * @brief Retrieves the type of the industrial building.
 * 
 * @return The type of the industrial building as a string.
 */
string Industrial::getType()
{
    return myType;
}

/**
 * @brief Retrieves the price of the industrial building.
 * 
 * @return The price of the industrial building as an integer.
 */
int Industrial::getPrice()
{
    return price[position];
}

/**
 * @brief Retrieves the position of the industrial building.
 * 
 * @return The position of the industrial building as an integer.
 */
int Industrial::getPosition()
{
    return position;
}

/**
 * @brief Retrieves the satisfaction rate of the industrial building.
 * 
 * @return The satisfaction rate as an integer.
 */
int Industrial::getSatisfaction()
{
    return satisfactionRate;
}

/**
 * @brief Sets the price of the industrial building.
 * 
 * @param pric The new price to be set for the industrial building.
 */
void Industrial::setPrice(int pric)
{
    price[position] = pric;
}

/**
 * @brief Checks if the industrial building is taken.
 * 
 * @return True if the building is taken, otherwise false.
 */
bool Industrial::getTaken()
{
    return taken;
}

/**
 * @brief Sets the occupancy status of the industrial building.
 * 
 * @param tak The new occupancy status (true for taken, false for available).
 */
void Industrial::setTaken(bool tak)
{
    taken = tak;
}
