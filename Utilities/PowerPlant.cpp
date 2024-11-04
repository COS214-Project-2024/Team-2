#include "PowerPlant.h"

/**
 * @brief Handles a resource request from the Government.
 * 
 * This method processes the request made by the Government by 
 * utilizing the necessary energy resource. It then calls the base 
 * class's handleRequest method to perform any additional processing 
 * defined in the Utilities class.
 * 
 * @param govern Pointer to the Government object that initiates the request.
 */
void PowerPlant::handleRequest(Government* govern) 
{
    govern->useResource("energy");
    Utilities::handleRequest(govern);
}
