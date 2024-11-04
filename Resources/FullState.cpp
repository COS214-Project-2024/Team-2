#include "FullState.h"
#include <iostream>

/**
 * @brief Uses a specified quantity of the resource.
 * 
 * This method outputs a message indicating the specified quantity of resource 
 * being used in the full state.
 * 
 * @param quantity The amount of resource to use.
 */
void FullState::useResource(int quantity) {
    std::cout << "FullState: Using " << quantity << " units of resource." << std::endl;
}

/**
 * @brief Generates a specified quantity of the resource.
 * 
 * This method outputs a message indicating the specified quantity of resource 
 * being generated in the full state.
 * 
 * @param quantity The amount of resource to generate.
 */
void FullState::generateResource(int quantity) {
    std::cout << "FullState: Generating " << quantity << " units of resource." << std::endl;
}
