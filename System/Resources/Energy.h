#ifndef ENERGY_H
#define ENERGY_H

#include "Resources.h"
#include "StateOfResources.h"

/**
 * @brief Represents an energy resource with varying states and quantities.
 * 
 * This class manages the quantity of energy and its state (full, empty, or normal).
 */
class Energy : public Resources {
private:
    int quantity; ///< Current quantity of the energy resource.
    StateOfResources* state; ///< Pointer to the current state of the energy resource.
    StateOfResources* fullState; ///< Pointer to the full state of the energy resource.
    StateOfResources* emptyState; ///< Pointer to the empty state of the energy resource.
    StateOfResources* normalState; ///< Pointer to the normal state of the energy resource.

public:
    /**
     * @brief Constructs an Energy object with the specified initial state and quantity.
     * 
     * @param initialState Pointer to the initial state of the energy resource.
     * @param initialQuantity The initial quantity of the energy resource.
     */
    Energy(StateOfResources* initialState, int initialQuantity);

    /**
     * @brief Uses a specified quantity of energy.
     * 
     * This method reduces the quantity of energy and updates the state based on the remaining quantity.
     * 
     * @param quantity The amount of energy to use.
     */
    void useResource(int quantity) override;

    /**
     * @brief Generates a specified quantity of energy.
     * 
     * This method increases the quantity of energy and updates the state based on the new quantity.
     * 
     * @param quantity The amount of energy to generate.
     */
    void generateResource(int quantity) override;

    /**
     * @brief Sets the current state of the energy resource.
     * 
     * @param newState Pointer to the new state to be set for the energy resource.
     */
    void setState(StateOfResources* newState);

    /**
     * @brief Gets the current quantity of the energy resource.
     * 
     * @return The current quantity of energy.
     */
    int getQuantity() const override;

    /**
     * @brief Gets the maximum capacity of the energy resource.
     * 
     * @return The maximum capacity of the energy resource, defined as a constant.
     */
    int getMaxCapacity() const override;
};

#endif
