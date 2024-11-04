#include "Utilities.h"
#include "../Government.h"

class MaterialFactory :public Utilities 
{
    public:
        void handleRequest(Government* govern) override;
};