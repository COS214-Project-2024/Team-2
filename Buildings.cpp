#include "Buildings.h"

/**
 * @brief Adds a building component.
 * 
 * @param component Pointer to the Buildings object to add.
 * @throws std::logic_error If the operation is not supported by the derived class.
 */
void Buildings::add(Buildings* component) 
{
    throw std::logic_error("Operation not supported");
}

/**
 * @brief Removes a building component.
 * 
 * @param component Pointer to the Buildings object to remove.
 * @throws std::logic_error If the operation is not supported by the derived class.
 */
void Buildings::remove(Buildings* component) 
{
    throw std::logic_error("Operation not supported");
}

/**
 * @brief Gets the type of the building.
 * 
 * @return A string representing the type of the building.
 * @throws std::logic_error If the operation is not supported by the derived class.
 */
string Buildings::getType() 
{
    throw std::logic_error("Operation not supported");
}

/**
 * @brief Gets the price of the building.
 * 
 * @return The price of the building.
 * @throws std::logic_error If the operation is not supported by the derived class.
 */
int Buildings::getPrice() 
{
    throw std::logic_error("Operation not supported");
}

/**
 * @brief Sets the price of the building.
 * 
 * @param p The price to set for the building.
 * @throws std::logic_error If the operation is not supported by the derived class.
 */
void Buildings::setPrice(int p) 
{
    throw std::logic_error("Operation not supported");
}

/**
 * @brief Checks if the building is occupied.
 * 
 * @return A boolean indicating if the building is occupied.
 * @throws std::logic_error If the operation is not supported by the derived class.
 */
bool Buildings::getTaken() 
{
    throw std::logic_error("Operation not supported");
}

/**
 * @brief Sets the occupancy status of the building.
 * 
 * @param b The occupancy status to set.
 * @throws std::logic_error If the operation is not supported by the derived class.
 */
void Buildings::setTaken(bool b) 
{
    throw std::logic_error("Operation not supported");
}
