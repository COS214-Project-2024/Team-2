#include "Wood.h"
#include "FullState.h"
#include "EmptyState.h"
#include "NormalState.h"
#include <iostream>

/**
 * @brief Constructs a Wood object with a specified initial state and quantity.
 * 
 * This constructor initializes the wood resource's state and quantity, 
 * and creates instances for the full, empty, and normal states.
 * 
 * @param initialState Pointer to the initial state of the wood resource.
 * @param initialQuantity The initial quantity of the wood resource.
 */
Wood::Wood(StateOfResources* initialState, int initialQuantity) : state(initialState), quantity(initialQuantity) {
    fullState = new FullState();
    emptyState = new EmptyState(this);
    normalState = new NormalState();
}

/**
 * @brief Uses a specified quantity of wood.
 * 
 * This method decreases the quantity of wood and updates the state based on the 
 * remaining quantity. If the quantity becomes zero or negative, the state is set to 
 * EmptyState. If it's less than the maximum capacity, it is set to NormalState; 
 * otherwise, it is set to FullState.
 * 
 * @param quantity The amount of wood to use.
 */
void Wood::useResource(int quantity) {
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
 * @brief Generates a specified quantity of wood.
 * 
 * This method increases the quantity of wood and updates the state based on the 
 * new quantity. If the quantity exceeds the maximum capacity, it is capped at that 
 * maximum, and the state is set to FullState. If it is positive but less than 
 * maximum, it is set to NormalState; if it is zero or less, it is set to EmptyState.
 * 
 * @param quantity The amount of wood to generate.
 */
void Wood::generateResource(int quantity) {
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
 * @brief Sets the state of the wood resource.
 * 
 * This method updates the current state of the wood resource to a new state.
 * 
 * @param newState Pointer to the new state to be set for the wood resource.
 */
void Wood::setState(StateOfResources* newState) {
    state = newState;
}

/**
 * @brief Gets the current quantity of wood.
 * 
 * @return The current quantity of wood.
 */
int Wood::getQuantity() const {
    return quantity;
}

/**
 * @brief Gets the maximum capacity of the wood resource.
 * 
 * @return The maximum capacity of wood, typically a fixed value.
 */
int Wood::getMaxCapacity() const {
    return 100; // Example max capacity
}
