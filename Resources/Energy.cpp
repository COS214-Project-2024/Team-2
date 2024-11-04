#include "Energy.h"
#include "FullState.h"
#include "EmptyState.h"
#include "NormalState.h"
#include <iostream>

/**
 * @brief Constructs an Energy object with the specified initial state and quantity.
 * 
 * Initializes the energy resource with an initial state and quantity,
 * and creates the various states associated with the energy resource.
 * 
 * @param initialState Pointer to the initial state of the energy resource.
 * @param initialQuantity The initial quantity of the energy resource.
 */
Energy::Energy(StateOfResources* initialState, int initialQuantity) 
    : state(initialState), quantity(initialQuantity) {
    fullState = new FullState();
    emptyState = new EmptyState(this);
    normalState = new NormalState();
}

/**
 * @brief Uses a specified quantity of energy.
 * 
 * This method reduces the quantity of energy by the specified amount,
 * updates the state of the resource, and ensures that the quantity does not drop below zero.
 * 
 * @param quantity The amount of energy to use.
 */
void Energy::useResource(int quantity) {
    state->useResource(quantity);
    this->quantity -= quantity;
    if (this->quantity <= 0) {
        this->quantity = 0;
        setState(emptyState);
    } else if (this->quantity < getMaxCapacity()) {
        setState(normalState);
    } else {
        setState(fullState);
    }
}

/**
 * @brief Generates a specified quantity of energy.
 * 
 * This method increases the quantity of energy by the specified amount,
 * updates the state based on the new quantity, and ensures it does not exceed maximum capacity.
 * 
 * @param quantity The amount of energy to generate.
 */
void Energy::generateResource(int quantity) {
    this->quantity += quantity;
    if (this->quantity >= getMaxCapacity()) {
        this->quantity = getMaxCapacity();
        setState(fullState);
    } else if (this->quantity > 0) {
        setState(normalState);
    } else {
        setState(emptyState);
    }
}

/**
 * @brief Sets the current state of the energy resource.
 * 
 * This method updates the state of the energy resource to the provided state.
 * 
 * @param newState Pointer to the new state to be set for the energy resource.
 */
void Energy::setState(StateOfResources* newState) {
    state = newState;
}

/**
 * @brief Gets the current quantity of the energy resource.
 * 
 * @return The current quantity of energy.
 */
int Energy::getQuantity() const {
    return quantity;
}

/**
 * @brief Gets the maximum capacity of the energy resource.
 * 
 * @return The maximum capacity of the energy resource, defined as a constant.
 */
int Energy::getMaxCapacity() const {
    return 100; // Example max capacity
}
