#include "WaterSupply.h"

/**
 * @brief Handles a water supply request from the Government.
 * 
 * This method uses the necessary resources related to water supply 
 * by calling the `useResource` method on the provided Government 
 * object. After processing the water resource, it delegates further 
 * handling to the next handler in the chain, if applicable.
 * 
 * @param govern Pointer to the Government object that initiates the 
 *               water supply request.
 */
void WaterSupply::handleRequest(Government* govern) 
{
    govern->useResource("water");
    Utilities::handleRequest(govern);
}
