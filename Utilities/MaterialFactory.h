#include "Utilities.h"
#include "Government.h"
#include "Wood.h"
#include "Steel.h"
#include "Concrete.h"

class MaterialFactory :public Utilities 
{
    public:
        void handleRequest(Government* govern) override;
};