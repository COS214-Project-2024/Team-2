#ifndef WATER_H
#define WATER_H

#include "Resources.h"
#include "StateOfResources.h"

/**
 * @brief Represents a water resource that can be used and generated.
 * 
 * This class manages the state and quantity of a water resource,
 * allowing for usage and generation of water while handling its
 * capacity states (Full, Empty, Normal).
 */
class Water : public Resources {
private:
    int quantity;                       ///< Current quantity of water.
    StateOfResources* state;           ///< Pointer to the current state of the water resource.
    StateOfResources* fullState;       ///< Pointer to the FullState of the water resource.
    StateOfResources* emptyState;      ///< Pointer to the EmptyState of the water resource.
    StateOfResources* normalState;     ///< Pointer to the NormalState of the water resource.

public:
    /**
     * @brief Constructs a Water object with a specified initial state and quantity.
     * 
     * @param initialState Pointer to the initial state of the water resource.
     * @param initialQuantity The initial quantity of the water resource.
     */
    Water(StateOfResources* initialState, int initialQuantity);

    /**
     * @brief Uses a specified quantity of water.
     * 
     * This method decreases the quantity of water and updates the state based 
     * on the remaining quantity. If the quantity becomes zero or negative, 
     * the state is set to EmptyState. If it's less than the maximum capacity, 
     * it's set to NormalState; otherwise, it's set to FullState.
     * 
     * @param quantity The amount of water to use.
     */
    void useResource(int quantity) override;

    /**
     * @brief Generates a specified quantity of water.
     * 
     * This method increases the quantity of water and updates the state based 
     * on the new quantity. If the quantity exceeds the maximum capacity, it's 
     * capped at that maximum, and the state is set to FullState. If it's positive 
     * but less than maximum, it's set to NormalState; if it is zero or less, 
     * it's set to EmptyState.
     * 
     * @param quantity The amount of water to generate.
     */
    void generateResource(int quantity) override;

    /**
     * @brief Sets the state of the water resource.
     * 
     * This method updates the current state of the water resource to a new state.
     * 
     * @param newState Pointer to the new state to be set for the water resource.
     */
    void setState(StateOfResources* newState);

    /**
     * @brief Gets the current quantity of water.
     * 
     * @return The current quantity of water.
     */
    int getQuantity() const override;

    /**
     * @brief Gets the maximum capacity of the water resource.
     * 
     * @return The maximum capacity of water, typically a fixed value.
     */
    int getMaxCapacity() const override;
};

#endif
