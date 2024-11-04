#include "StateOfResources.h"
#include "Resources.h"

/**
 * @brief Represents the empty state of a resource.
 * 
 * The EmptyState class implements the StateOfResources interface, defining 
 * the behavior of a resource when it is in an empty state.
 */
class EmptyState : public StateOfResources {
private:
    Resources* resource; ///< Pointer to the resource associated with this state.

public:
    /**
     * @brief Constructs an EmptyState object for a given resource.
     * 
     * @param resource Pointer to the resource that is in the empty state.
     */
    EmptyState(Resources* resource);

    /**
     * @brief Handles the usage of a specified quantity of the resource.
     * 
     * In the empty state, this method typically would not allow the 
     * consumption of resources. The behavior can be defined based on 
     * specific requirements, such as throwing an exception or logging 
     * a warning.
     * 
     * @param quantity The amount of resource to use.
     */
    void useResource(int quantity) override;

    /**
     * @brief Generates a specified quantity of the resource.
     * 
     * This method updates the associated resource, transitioning it 
     * from the empty state to another state if resources are generated.
     * 
     * @param quantity The amount of resource to generate.
     */
    void generateResource(int quantity) override;
};
