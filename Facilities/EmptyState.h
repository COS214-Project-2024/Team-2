#include "StateOfResources.h"

class EmptyState : public StateOfResources {
    public:
        void useResource(int quantity) override;
        void generateResource(int quantity) override;
};