#include "StateOfResources.h"

class Resources {
    private:
        int maxCapacity;
    public:
        virtual void useResource(int quantity) = 0;
};