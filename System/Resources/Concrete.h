#include "Materials.h"
#include "StateOfResources.h"

/**
 * @brief Represents a concrete material in the resource management system.
 * 
 * The Concrete class manages the quantity of concrete resources, 
 * and tracks its state using various `StateOfResources`. It supports 
 * resource usage and generation, as well as state transitions.
 */
class Concrete : public Materials {
private:
    int quantity;                    ///< Current quantity of concrete.
    StateOfResources* state;        ///< Pointer to the current state of the concrete.
    StateOfResources* fullState;    ///< Pointer to the full state of concrete.
    StateOfResources* emptyState;   ///< Pointer to the empty state of concrete.
    StateOfResources* normalState;  ///< Pointer to the normal state of concrete.

public:
    /**
     * @brief Constructs a Concrete object with an initial state and quantity.
     * 
     * @param initialState Pointer to the initial state of the concrete.
     * @param initialQuantity The initial quantity of concrete.
     */
    Concrete(StateOfResources* initialState, int initialQuantity);

    /**
     * @brief Uses a specified quantity of concrete.
     * 
     * Reduces the current quantity of concrete by the specified amount, 
     * potentially updating the state if necessary.
     * 
     * @param quantity The amount of concrete to use.
     */
    void useResource(int quantity) override;

    /**
     * @brief Generates a specified quantity of concrete.
     * 
     * Increases the current quantity of concrete by the specified amount, 
     * ensuring it does not exceed maximum capacity.
     * 
     * @param quantity The amount of concrete to generate.
     */
    void generateResource(int quantity) override;

    /**
     * @brief Sets a new state for the concrete.
     * 
     * Updates the current state of the concrete to the specified new state.
     * 
     * @param newState Pointer to the new state to be set.
     */
    void setState(StateOfResources* newState);

    /**
     * @brief Retrieves the current quantity of concrete.
     * 
     * @return The current quantity of concrete.
     */
    int getQuantity() const override;

    /**
     * @brief Retrieves the maximum capacity for concrete.
     * 
     * @return The maximum capacity for this concrete resource.
     */
    int getMaxCapacity() const override;
};
