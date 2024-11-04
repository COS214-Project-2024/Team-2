#include "Concrete.h"
#include "FullState.h"
#include "EmptyState.h"
#include "NormalState.h"
#include <iostream>

/**
 * @brief Constructs a Concrete object with an initial state and quantity.
 * 
 * @param initialState Pointer to the initial state of the concrete.
 * @param initialQuantity The initial quantity of concrete.
 */
Concrete::Concrete(StateOfResources* initialState, int initialQuantity) 
    : state(initialState), quantity(initialQuantity) {
    fullState = new FullState();    ///< Initialize the full state of concrete.
    emptyState = new EmptyState(this); ///< Initialize the empty state of concrete.
    normalState = new NormalState(); ///< Initialize the normal state of concrete.
}

/**
 * @brief Uses a specified quantity of concrete.
 * 
 * This method reduces the current quantity of concrete by the specified 
 * amount, updates the quantity, and changes the state based on the new 
 * quantity. If the quantity falls to zero or below, the state changes 
 * to empty; if it is below the maximum capacity, the state changes to normal; 
 * otherwise, it changes to full.
 * 
 * @param quantity The amount of concrete to use.
 */
void Concrete::useResource(int quantity) {
    state->useResource(quantity); // Delegate the use to the current state.
    this->quantity -= quantity;
    
    if (this->quantity <= 0) {
        this->quantity = 0; // Prevent negative quantity.
        setState(emptyState); // Change state to empty.
    } else if (this->quantity < getMaxCapacity()) {
        setState(normalState); // Change state to normal.
    } else {
        setState(fullState); // Change state to full.
    }
}

/**
 * @brief Generates a specified quantity of concrete.
 * 
 * This method increases the current quantity of concrete by the specified 
 * amount, updates the quantity, and changes the state based on the new 
 * quantity. If the quantity exceeds the maximum capacity, it sets it 
 * to the maximum and changes the state to full; if the quantity is 
 * greater than zero, it sets the state to normal; if the quantity is 
 * zero, it sets the state to empty.
 * 
 * @param quantity The amount of concrete to generate.
 */
void Concrete::generateResource(int quantity) {
    this->quantity += quantity;
    
    if (this->quantity >= getMaxCapacity()) {
        this->quantity = getMaxCapacity(); // Cap the quantity at maximum.
        setState(fullState); // Change state to full.
    } else if (this->quantity > 0) {
        setState(normalState); // Change state to normal.
    } else {
        setState(emptyState); // Change state to empty.
    }
}

/**
 * @brief Sets a new state for the concrete.
 * 
 * This method updates the current state of the concrete to the specified 
 * new state.
 * 
 * @param newState Pointer to the new state to be set.
 */
void Concrete::setState(StateOfResources* newState) {
    state = newState;
}

/**
 * @brief Retrieves the current quantity of concrete.
 * 
 * @return The current quantity of concrete.
 */
int Concrete::getQuantity() const {
    return quantity;
}

/**
 * @brief Retrieves the maximum capacity for concrete.
 * 
 * @return The maximum capacity for this concrete resource.
 */
int Concrete::getMaxCapacity() const {
    return 100; // Example max capacity.
}
