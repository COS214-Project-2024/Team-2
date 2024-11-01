#include "Utilities.h"
#include "Government.h"
#include "Water.h"

class WaterSupply :public Utilities 
{
    public:
        void handleRequest(Government* govern) override;
};