#include "Utilities.h"
#include "Government.h"
#include "Energy.h"

class PowerPlant :public Utilities {
    public:
        void handleRequest(Government* govern) override;
};