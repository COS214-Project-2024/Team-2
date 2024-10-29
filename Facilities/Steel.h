#include "Materials.h"

class Steel : public Materials{
    private:
        int quantity;
        StateOfResources state;
    public:
        void useResource(int quantity);
};