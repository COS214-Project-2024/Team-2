#include "Energy.h"
#include "FullState.h"
#include "EmptyState.h"
#include "NormalState.h"
#include <iostream>

Energy::Energy(StateOfResources* initialState, int initialQuantity) : state(initialState), quantity(initialQuantity) {
    fullState = new FullState();
    emptyState = new EmptyState(this);
    normalState = new NormalState();
}

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

void Energy::setState(StateOfResources* newState) {
    state = newState;
}

int Energy::getQuantity() const {
    return quantity;
}

int Energy::getMaxCapacity() const {
    return 100;
}