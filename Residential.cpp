#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Residential.h"

using namespace std;

/**
 * @brief Constructs a Residential object of a specified type.
 * 
 * This constructor initializes the position of the residential building
 * based on the provided type.
 * 
 * @param t The type of residential building to create.
 */
Residential::Residential(string t)
{
    for(int i = 0; i < 3; i++)
    {
        if(type[i] == t)
        {
            position = i; // Set the position based on the type
        }
    }
}

/**
 * @brief Retrieves the type of the residential building.
 * 
 * @return A string representing the type of building.
 */
string Residential::getType()
{
    return myType;
}

/**
 * @brief Retrieves the price of the residential building.
 * 
 * @return The price of the building corresponding to its type.
 */
int Residential::getPrice()
{
    return price[position];
}

/**
 * @brief Retrieves the position/index of the building type.
 * 
 * @return The position of the building type in the array.
 */
int Residential::getPosition()
{
    return position;
}

/**
 * @brief Retrieves the satisfaction rate of the residential building.
 * 
 * @return The satisfaction rate.
 */
int Residential::getSatisfaction()
{
    return satisfactionRate;
}

/**
 * @brief Sets the price of the residential building.
 * 
 * @param pric The new price to set for the building.
 */
void Residential::setPrice(int pric)
{
    price[position] = pric;
}

/**
 * @brief Checks if the residential building type is taken.
 * 
 * @return True if the building type is taken, false otherwise.
 */
bool Residential::getTaken()
{
    return taken;
}

/**
 * @brief Sets the taken status of the residential building type.
 * 
 * @param tak The new taken status to set.
 */
void Residential::setTaken(bool tak)
{
    taken = tak;
}
