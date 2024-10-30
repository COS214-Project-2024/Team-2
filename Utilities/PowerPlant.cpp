#include "PowerPlant.h"

void PowerPlant::handleRequest(Government* govern) override {
    govern->userResource("energy");
    Utilities::handleRequest(govern);
};