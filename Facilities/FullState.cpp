#include "FullState.h"
#include <iostream>

void FullState::useResource(int quantity) {
    std::cout << "FullState: Using " << quantity << " units of resource." << std::endl;
}

void FullState::generateResource(int quantity) {
    std::cout << "FullState: Generating " << quantity << " units of resource." << std::endl;
}