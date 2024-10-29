#include "Materials.h"
#include "StateOfResources.h"

class Wood : public Materials {
    private:
        int quantity;
        StateOfResources state;
    public:
        Wood(StateOfResources initialState, int initialQuantity) : state(initialState), quantity(initialQuantity) {}
        void useResource(int quantity) override;
};