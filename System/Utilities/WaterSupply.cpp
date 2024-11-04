#include "WaterSupply.h"

void WaterSupply::handleRequest(Government* govern) 
{
    govern->useResource("water");
    Utilities::handleRequest(govern);
}
