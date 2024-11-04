#ifndef UTILITIES_H
#define UTILITIES_H

#include "../Government.h"

/**
 * @brief Abstract base class for utility handlers.
 * 
 * This class defines the common interface and behavior for utility 
 * handlers that can process requests from the Government. It implements 
 * the Chain of Responsibility pattern, allowing handlers to pass 
 * requests to the next handler in the chain.
 */
class Utilities {
protected:
    Utilities* nextHandler; ///< Pointer to the next handler in the chain.

public:
    /**
     * @brief Constructs a Utilities object.
     * 
     * Initializes the nextHandler pointer to nullptr.
     */
    Utilities() : nextHandler(nullptr) {}

    /**
     * @brief Destructor for the Utilities class.
     * 
     * Cleans up resources associated with the Utilities object.
     */
    virtual ~Utilities() {}

    /**
     * @brief Sets the next handler in the chain.
     * 
     * @param next Pointer to the next Utilities handler to set.
     */
    void setNext(Utilities* next) {
        nextHandler = next;
    }

    /**
     * @brief Handles a request from the Government.
     * 
     * This method attempts to process a request from the Government. 
     * If there is a next handler in the chain, the request is passed 
     * to that handler for further processing.
     * 
     * @param govern Pointer to the Government object that initiates the request.
     */
    virtual void handleRequest(Government* govern) {
        if (nextHandler) {
            nextHandler->handleRequest(govern);
        }
    }
};

#endif
