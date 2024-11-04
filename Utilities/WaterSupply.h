#include "Utilities.h"
#include "../Government.h"

class WaterSupply :public Utilities 
{
    public:
        void handleRequest(Government* govern) override;
};