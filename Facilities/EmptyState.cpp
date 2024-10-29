#include "EmptyState.h"
#include <iostream>

void EmptyState::useResource(int quantity) {
    std::cout << "EmptyState: Using " << quantity << " units of resource." << std::endl;
    if (quantity <= 0) {
        std::cout << "EmptyState: Resource quantity is low, increasing quantity." << std::endl;
        generateResource(10);
    }
}

void EmptyState::generateResource(int quantity) {
    std::cout << "EmptyState: Generating " << quantity << " units of resource." << std::endl;
}