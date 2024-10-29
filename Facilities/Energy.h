#include "Resources.h"

class Energy : public Resources {
    private:
        int quantity;
        StateOfResources state;
    public:
        void useResource(int quantity) override;
};