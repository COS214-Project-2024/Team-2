#include "MaterialFactory.h"

void MaterialFactory::handleRequest(Government* govern) override {
    govern->userResource("steel");
    govern->userResource("wood");
    govern->userResource("concrete");
    Utilities::handleRequest(govern);
};