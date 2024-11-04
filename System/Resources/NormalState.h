#include "StateOfResources.h"

/**
 * @class NormalState
 * @brief Class representing the normal state of a resource.
 * 
 * This class implements the behavior of a resource when it is in a normal state,
 * allowing for the use and generation of the resource.
 */
class NormalState : public StateOfResources {
    public:
        /**
         * @brief Uses a specified quantity of the resource.
         * 
         * In the normal state, the resource can be used. The behavior for using the
         * resource is defined in this implementation.
         * 
         * @param quantity The amount of resource to use.
         */
        void useResource(int quantity) override;

        /**
         * @brief Generates a specified quantity of the resource.
         * 
         * In the normal state, the resource can also be generated. The behavior for
         * generating the resource is defined in this implementation.
         * 
         * @param quantity The amount of resource to generate.
         */
        void generateResource(int quantity) override;
};
