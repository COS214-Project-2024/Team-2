#include "NormalState.h"
#include <iostream>

/**
 * @brief Uses a specified quantity of the resource in the normal state.
 * 
 * This function simulates the usage of a resource in its normal state. It
 * prints a message indicating the quantity of resource being used.
 * 
 * @param quantity The amount of resource to use.
 */
void NormalState::useResource(int quantity) {
    std::cout << "NormalState: Using " << quantity << " units of resource." << std::endl;
}

/**
 * @brief Generates a specified quantity of the resource in the normal state.
 * 
 * This function simulates the generation of a resource in its normal state. It
 * prints a message indicating the quantity of resource being generated.
 * 
 * @param quantity The amount of resource to generate.
 */
void NormalState::generateResource(int quantity) {
    std::cout << "NormalState: Generating " << quantity << " units of resource." << std::endl;
}
