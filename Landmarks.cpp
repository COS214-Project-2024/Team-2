#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Landmarks.h"

using namespace std;

/**
 * @brief Constructor for the Landmarks class.
 * 
 * This constructor initializes a Landmarks object based on the specified
 * type and sets the position index accordingly.
 * 
 * @param t The type of the landmark (parks, monuments, culturecenters).
 */
Landmarks::Landmarks(string t)
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
 * @brief Retrieves the type of the landmark.
 * 
 * @return The type of the landmark as a string.
 */
string Landmarks::getType()
{
    return myType;
}

/**
 * @brief Retrieves the price of the landmark.
 * 
 * @return The price of the landmark as an integer.
 */
int Landmarks::getPrice()
{
    return price[position];
}

/**
 * @brief Retrieves the position of the landmark in the type array.
 * 
 * @return The position of the landmark as an integer.
 */
int Landmarks::getPosition()
{
    return position;
}

/**
 * @brief Retrieves the satisfaction rate of the landmark.
 * 
 * @return The satisfaction rate as an integer.
 */
int Landmarks::getSatisfaction()
{
    return satisfactionRate;
}

/**
 * @brief Sets the price of the landmark.
 * 
 * @param pric The new price for the landmark.
 */
void Landmarks::setPrice(int pric)
{
    price[position] = pric;
}

/**
 * @brief Checks if the landmark is taken.
 * 
 * @return true if the landmark is taken, false otherwise.
 */
bool Landmarks::getTaken()
{
    return taken;
}

/**
 * @brief Sets the taken status of the landmark.
 * 
 * @param tak The new taken status.
 */
void Landmarks::setTaken(bool tak)
{
    taken = tak;
}
