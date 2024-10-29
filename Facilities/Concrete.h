#include "Materials.h"
#include "StateOfResources.h"

class Concrete : public Materials {
private:
    int quantity;
    StateOfResources* state;
    StateOfResources* fullState;
    StateOfResources* emptyState;
    StateOfResources* normalState;

public:
    Concrete(StateOfResources* initialState, int initialQuantity);
    void useResource(int quantity) override;
    void generateResource(int quantity) override;
    void setState(StateOfResources* newState);
    int getQuantity() const override;
    int getMaxCapacity() const override;
};