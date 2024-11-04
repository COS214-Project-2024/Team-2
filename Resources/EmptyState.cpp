#include "EmptyState.h"
#include <iostream>

EmptyState::EmptyState(Resources* resource) : resource(resource) {}

void EmptyState::useResource(int quantity) {
    std::cout << "EmptyState: Resource quantity is low, increasing quantity." << std::endl;
    this->generateResource(quantity);
}

void EmptyState::generateResource(int quantity) {
    std::cout << "EmptyState: Generating " << quantity << " units of resource." << std::endl;
    resource->generateResource(quantity);
}