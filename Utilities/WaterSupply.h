#include "Utilities.h"
#include "../Government.h"

/**
 * @brief Concrete handler for managing water supply requests.
 * 
 * The WaterSupply class is a specific implementation of the Utilities 
 * handler that processes requests related to water supply management 
 * from the Government.
 */
class WaterSupply : public Utilities 
{
public:
    /**
     * @brief Handles a water supply request from the Government.
     * 
     * This method uses the necessary resources related to water supply 
     * and delegates further handling to the next handler in the chain, 
     * if applicable.
     * 
     * @param govern Pointer to the Government object that initiates the 
     *               water supply request.
     */
    void handleRequest(Government* govern) override;
};
