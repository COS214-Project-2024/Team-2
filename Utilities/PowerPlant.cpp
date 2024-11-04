#include "PowerPlant.h"

void PowerPlant::handleRequest(Government* govern) 
{
    govern->useResource("energy");
    Utilities::handleRequest(govern);
}
