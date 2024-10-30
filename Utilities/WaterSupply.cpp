#include "WaterSupply.h"

void WaterSupply::handleRequest(Government* govern) override {
    govern->userResource("water");
    Utilities::handleRequest(govern);
}