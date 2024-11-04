#include "MaterialFactory.h"

/**
 * @brief Handles a material request from the Government.
 * 
 * This method processes a request from the Government by utilizing specific 
 * resources needed for material handling. It calls the `useResource` method 
 * on the Government object for the materials: steel, wood, and concrete. 
 * After using these resources, it delegates further handling to the 
 * `handleRequest` method of the parent Utilities class.
 * 
 * @param govern Pointer to the Government object that initiates the request.
 */
void MaterialFactory::handleRequest(Government* govern)
{
    govern->useResource("steel");
    govern->useResource("wood");
    govern->useResource("concrete");
    Utilities::handleRequest(govern);
}
