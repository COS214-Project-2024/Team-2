#include "NormalState.h"
#include <iostream>

void NormalState::useResource(int quantity) {
    std::cout << "NormalState: Using " << quantity << " units of resource." << std::endl;
}

void NormalState::generateResource(int quantity) {
    std::cout << "NormalState: Generating " << quantity << " units of resource." << std::endl;
}