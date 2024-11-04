#include "EmptyState.h"
#include <iostream>

/**
 * @brief Constructs an EmptyState object for the specified resource.
 * 
 * @param resource Pointer to the resource that is in the empty state.
 */
EmptyState::EmptyState(Resources* resource) : resource(resource) {}

/**
 * @brief Handles the usage of a specified quantity of the resource.
 * 
 * In the empty state, this method outputs a message indicating that the 
 * resource quantity is low and triggers the generation of more resources.
 * 
 * @param quantity The amount of resource to use, which will lead to 
 *                an attempt to generate more of the resource.
 */
void EmptyState::useResource(int quantity) {
    std::cout << "EmptyState: Resource quantity is low, increasing quantity." << std::endl;
    this->generateResource(quantity);
}

/**
 * @brief Generates a specified quantity of the resource.
 * 
 * This method outputs a message indicating the quantity being generated 
 * and calls the generateResource method of the associated resource to 
 * increase its quantity.
 * 
 * @param quantity The amount of resource to generate.
 */
void EmptyState::generateResource(int quantity) {
    std::cout << "EmptyState: Generating " << quantity << " units of resource." << std::endl;
    resource->generateResource(quantity);
}
