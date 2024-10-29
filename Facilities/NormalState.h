#include "StateOfResources.h"

class NormalState : public StateOfResources {
    public:
        void useResource(int quantity) override;
        void generateResource(int quantity) override;
};