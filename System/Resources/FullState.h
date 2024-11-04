#include "StateOfResources.h"

/**
 * @brief Represents the full state of a resource.
 * 
 * This class is a concrete implementation of the StateOfResources interface,
 * which defines the behavior of a resource when it is in a full state.
 */
class FullState : public StateOfResources {
    public:
        /**
         * @brief Uses a specified quantity of the resource.
         * 
         * In the full state, attempting to use a resource may trigger a warning or
         * generate more resources instead, depending on the implementation.
         * 
         * @param quantity The amount of resource to use.
         */
        void useResource(int quantity) override;

        /**
         * @brief Generates a specified quantity of the resource.
         * 
         * In the full state, this method may have different behavior compared
         * to other states, often allowing for resource generation without limits.
         * 
         * @param quantity The amount of resource to generate.
         */
        void generateResource(int quantity) override;
};
