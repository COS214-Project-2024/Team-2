#include "Water.h"
#include "FullState.h"
#include "EmptyState.h"
#include "NormalState.h"
#include <iostream>

/**
 * @brief Constructs a Water object with a specified initial state and quantity.
 * 
 * This constructor initializes the water resource's state and quantity, 
 * and creates instances for the full, empty, and normal states.
 * 
 * @param initialState Pointer to the initial state of the water resource.
 * @param initialQuantity The initial quantity of the water resource.
 */
Water::Water(StateOfResources* initialState, int initialQuantity) 
    : state(initialState), quantity(initialQuantity) {
    fullState = new FullState();
    emptyState = new EmptyState(this);
    normalState = new NormalState();
}

/**
 * @brief Uses a specified quantity of water.
 * 
 * This method decreases the quantity of water and updates the state based on the 
 * remaining quantity. If the quantity becomes zero or negative, the state is set to 
 * EmptyState. If it's less than the maximum capacity, it is set to NormalState; 
 * otherwise, it is set to FullState.
 * 
 * @param quantity The amount of water to use.
 */
void Water::useResource(int quantity) {
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
 * @brief Generates a specified quantity of water.
 * 
 * This method increases the quantity of water and updates the state based on the 
 * new quantity. If the quantity exceeds the maximum capacity, it is capped at that 
 * maximum, and the state is set to FullState. If it is positive but less than 
 * maximum, it is set to NormalState; if it is zero or less, it is set to EmptyState.
 * 
 * @param quantity The amount of water to generate.
 */
void Water::generateResource(int quantity) {
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
 * @brief Sets the state of the water resource.
 * 
 * This method updates the current state of the water resource to a new state.
 * 
 * @param newState Pointer to the new state to be set for the water resource.
 */
void Water::setState(StateOfResources* newState) {
    state = newState;
}

/**
 * @brief Gets the current quantity of water.
 * 
 * @return The current quantity of water.
 */
int Water::getQuantity() const {
    return quantity;
}

/**
 * @brief Gets the maximum capacity of the water resource.
 * 
 * @return The maximum capacity of water, typically a fixed value.
 */
int Water::getMaxCapacity() const {
    return 100; // Example maximum capacity
}
