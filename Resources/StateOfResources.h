#ifndef STATEOFRESOURCES_H
#define STATEOFRESOURCES_H

/**
 * @class StateOfResources
 * @brief Abstract base class representing the state of resources.
 *
 * This class defines the interface for different states of a resource,
 * including how to use and generate resources based on their current state.
 */
class StateOfResources {
    public:
        /**
         * @brief Uses a specified quantity of the resource based on the current state.
         * 
         * This pure virtual function must be implemented by derived classes to 
         * define how the resource is used in the context of its current state.
         * 
         * @param quantity The amount of resource to use.
         */
        virtual void useResource(int quantity) = 0;

        /**
         * @brief Generates a specified quantity of the resource based on the current state.
         * 
         * This pure virtual function must be implemented by derived classes to 
         * define how the resource is generated in the context of its current state.
         * 
         * @param quantity The amount of resource to generate.
         */
        virtual void generateResource(int quantity) = 0;
};

#endif
