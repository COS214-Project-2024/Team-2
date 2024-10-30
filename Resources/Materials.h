#include "Resources.h"

class Materials : public Resources {
    public:
        virtual void useResource(int quantity) override = 0;
        virtual void generateResource(int quantity) override = 0;
        virtual void useMaterialType() = 0;
};