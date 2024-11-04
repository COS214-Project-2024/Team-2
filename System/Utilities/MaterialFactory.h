#include "Utilities.h"
#include "../Government.h"

/**
 * @class MaterialFactory
 * @brief A factory class for handling material requests in the context of a Government.
 * 
 * The MaterialFactory class inherits from the Utilities class and implements 
 * functionality to handle requests related to materials that the Government 
 * may require. This class serves as a key component in the management 
 * of resources within the government system.
 */
class MaterialFactory : public Utilities 
{
    public:
        /**
         * @brief Handles a material request from the Government.
         * 
         * This method processes the incoming request by performing the necessary
         * operations required to fulfill the request for materials. It interacts
         * with the Government object to achieve this.
         * 
         * @param govern Pointer to the Government object that initiates the request.
         */
        void handleRequest(Government* govern) override;
};
