#include "Resources.h"

class Materials : public Resources {
    private:
        StateOfResources state;
    public:
        virtual void useResource(int quantity) = 0;
        virtual void useMaterialType() = 0;
};