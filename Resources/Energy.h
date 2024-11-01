#ifndef ENERGY_H
#define ENERGY_H

#include "Resources.h"
#include "StateOfResources.h"

class Energy : public Resources {
private:
    int quantity;
    StateOfResources* state;
    StateOfResources* fullState;
    StateOfResources* emptyState;
    StateOfResources* normalState;

public:
    Energy(StateOfResources* initialState, int initialQuantity);
    void useResource(int quantity) override;
    void generateResource(int quantity) override;
    void setState(StateOfResources* newState);
    int getQuantity() const override;
    int getMaxCapacity() const override;
};

#endif