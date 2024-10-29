#include "NormalState.h"
#include <iostream>

void NormalState::useResource(int quantity) {
    std::cout << "NormalState: Using " << quantity << " units of resource." << std::endl;
    if (quantity > 0) {
        std::cout << "NormalState: Resource quantity is sufficient, lowering quantity." << std::endl;
    }
}

void NormalState::generateResource(int quantity) {
    std::cout << "NormalState: Generating " << quantity << " units of resource." << std::endl;
}