#include "Wood.h"
#include <iostream>

void Wood::useResource(int quantity) {
    std::cout << "Wood: Using " << quantity << " units of resource." << std::endl;
    useResource(quantity);
    this->quantity -= quantity;
    if (this->quantity <= 0) {
        std::cout << "Wood: Resource quantity is low, generating more resources." << std::endl;
        generateResource(10);
        this->quantity += 10;
    }
}