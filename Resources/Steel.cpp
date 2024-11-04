#include "Steel.h"
#include "FullState.h"
#include "EmptyState.h"
#include "NormalState.h"
#include <iostream>

/**
 * @brief Constructs a Steel object with a specified initial state and quantity.
 *
 * @param initialState Pointer to the initial state of the steel resource.
 * @param initialQuantity The initial quantity of the steel resource.
 */
Steel::Steel(StateOfResources* initialState, int initialQuantity) 
    : state(initialState), quantity(initialQuantity) {
    fullState = new FullState();    ///< Create a new FullState instance.
    emptyState = new EmptyState(this); ///< Create a new EmptyState instance, passing this Steel object.
    normalState = new NormalState(); ///< Create a new NormalState instance.
}

/**
 * @brief Uses a specified quantity of steel.
 * 
 * This method decreases the quantity of steel and updates the state based on 
 * the remaining quantity. If the quantity becomes zero or negative, the state 
 * is set to EmptyState. If it's less than the maximum capacity, it's set to 
 * NormalState; otherwise, it's set to FullState.
 * 
 * @param quantity The amount of steel to use.
 */
void Steel::useResource(int quantity) {
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
 * @brief Generates a specified quantity of steel.
 * 
 * This method increases the quantity of steel and updates the state based on 
 * the new quantity. If the quantity exceeds the maximum capacity, it's capped 
 * at that maximum, and the state is set to FullState. If it's positive but 
 * less than maximum, it's set to NormalState; if it is zero or less, it's 
 * set to EmptyState.
 * 
 * @param quantity The amount of steel to generate.
 */
void Steel::generateResource(int quantity) {
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
 * @brief Sets the state of the steel resource.
 * 
 * This method updates the current state of the steel resource to a new state.
 * 
 * @param newState Pointer to the new state to be set for the steel resource.
 */
void Steel::setState(StateOfResources* newState) {
    state = newState;
}

/**
 * @brief Gets the current quantity of steel.
 * 
 * @return The current quantity of steel.
 */
int Steel::getQuantity() const {
    return quantity;
}

/**
 * @brief Gets the maximum capacity of the steel resource.
 * 
 * @return The maximum capacity of steel, typically a fixed value.
 */
int Steel::getMaxCapacity() const {
    return 100; // Example max capacity
}
