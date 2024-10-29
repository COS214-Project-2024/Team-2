#include "StateOfResources.h"
#include "Resources.h"

class EmptyState : public StateOfResources {
private:
    Resources* resource;
public:
    EmptyState(Resources* resource);
    void useResource(int quantity) override;
    void generateResource(int quantity) override;
};