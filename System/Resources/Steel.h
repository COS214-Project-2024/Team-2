#include "Materials.h"
#include "StateOfResources.h"

/**
 * @class Steel
 * @brief Class representing the Steel material resource.
 *
 * The Steel class is derived from the Materials class and manages the quantity and
 * state of steel resources. It implements methods for using and generating steel 
 * while handling its current state.
 */
class Steel : public Materials {
private:
    int quantity;  ///< The current quantity of steel.
    StateOfResources* state;  ///< Pointer to the current state of the steel resource.
    StateOfResources* fullState;  ///< Pointer to the full state of the steel resource.
    StateOfResources* emptyState;  ///< Pointer to the empty state of the steel resource.
    StateOfResources* normalState;  ///< Pointer to the normal state of the steel resource.

public:
    /**
     * @brief Constructs a Steel object with a specified initial state and quantity.
     *
     * @param initialState Pointer to the initial state of the steel resource.
     * @param initialQuantity The initial quantity of the steel resource.
     */
    Steel(StateOfResources* initialState, int initialQuantity);

    /**
     * @brief Uses a specified quantity of steel.
     * 
     * This method decreases the quantity of steel and updates the state based on 
     * the remaining quantity.
     * 
     * @param quantity The amount of steel to use.
     */
    void useResource(int quantity) override;

    /**
     * @brief Generates a specified quantity of steel.
     * 
     * This method increases the quantity of steel and updates the state based on 
     * the new quantity.
     * 
     * @param quantity The amount of steel to generate.
     */
    void generateResource(int quantity) override;

    /**
     * @brief Sets the state of the steel resource.
     * 
     * This method updates the current state of the steel resource to a new state.
     * 
     * @param newState Pointer to the new state to be set for the steel resource.
     */
    void setState(StateOfResources* newState);

    /**
     * @brief Gets the current quantity of steel.
     * 
     * @return The current quantity of steel.
     */
    int getQuantity() const override;

    /**
     * @brief Gets the maximum capacity of the steel resource.
     * 
     * @return The maximum capacity of steel, typically a fixed value.
     */
    int getMaxCapacity() const override;
};
