#include "Resources.h"

class Water : public Resources {
    private:
        int quantity;
        StateOfResources state;
    public:
        void useResource(int quantity) override;
};