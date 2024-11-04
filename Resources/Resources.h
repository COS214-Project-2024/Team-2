#ifndef RESOURCES_H
#define RESOURCES_H

/**
 * @class Resources
 * @brief Abstract base class for managing resources.
 *
 * This class defines the interface for resource management, including
 * methods for using and generating resources, as well as retrieving 
 * the current quantity and maximum capacity of a resource.
 */
class Resources 
{
    private:
        int maxCapacity; ///< Maximum capacity of the resource.

    public:
        /**
         * @brief Uses a specified quantity of the resource.
         * 
         * This pure virtual function must be implemented by derived classes
         * to define how a resource is used.
         * 
         * @param quantity The amount of resource to use.
         */
        virtual void useResource(int quantity) = 0;

        /**
         * @brief Generates a specified quantity of the resource.
         * 
         * This pure virtual function must be implemented by derived classes
         * to define how a resource is generated.
         * 
         * @param quantity The amount of resource to generate.
         */
        virtual void generateResource(int quantity) = 0;

        /**
         * @brief Gets the current quantity of the resource.
         * 
         * This pure virtual function must be implemented by derived classes
         * to return the current amount of resource available.
         * 
         * @return The current quantity of the resource.
         */
        virtual int getQuantity() const = 0;

        /**
         * @brief Gets the maximum capacity of the resource.
         * 
         * This pure virtual function must be implemented by derived classes
         * to return the maximum amount of resource that can be held.
         * 
         * @return The maximum capacity of the resource.
         */
        virtual int getMaxCapacity() const = 0;
};

#endif
