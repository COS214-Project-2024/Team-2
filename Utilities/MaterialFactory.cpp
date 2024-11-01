#include "MaterialFactory.h"

void MaterialFactory::handleRequest(Government* govern)
{
    govern->useResource("steel");
    govern->useResource("wood");
    govern->useResource("concrete");
    Utilities::handleRequest(govern);
}
