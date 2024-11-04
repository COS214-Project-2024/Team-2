#include "Utilities.h"
#include "../Government.h"

/**
 * @brief A class that represents a Power Plant.
 * 
 * The PowerPlant class is responsible for handling resource requests 
 * from the Government. It inherits from the Utilities class to utilize 
 * shared functionality for resource management.
 */
class PowerPlant : public Utilities 
{
    public:
        /**
         * @brief Handles a resource request from the Government.
         * 
         * This method processes the request made by the Government by 
         * utilizing the necessary resources. Specific implementation details 
         * on how resources are managed should be defined in the derived 
         * class.
         * 
         * @param govern Pointer to the Government object that initiates the request.
         */
        void handleRequest(Government* govern) override;
};
