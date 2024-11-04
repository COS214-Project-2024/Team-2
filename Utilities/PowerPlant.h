#include "Utilities.h"
#include "../Government.h"

class PowerPlant :public Utilities 
{
    public:
        void handleRequest(Government* govern) override;
};