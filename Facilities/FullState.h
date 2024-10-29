#include "StateOfResources.h"

class FullState : public StateOfResources {
    public:
        void useResource(int quantity) override;
        void generateResource(int quantity) override;
};