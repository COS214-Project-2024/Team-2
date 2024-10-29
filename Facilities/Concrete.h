#include "Materials.h"

class Concrete : public Materials {
    private:
        int quantity;
        StateOfResources state;
    public:
        void useResource(int quantity);
};