#include "Materials.h"
#include "StateOfResources.h"

/**
 * @brief Represents a Wood resource in the system.
 * 
 * The Wood class is derived from the Materials class and manages the quantity of wood 
 * resources and their states (Full, Empty, Normal). It allows for using and generating 
 * wood resources while ensuring the state transitions based on the current quantity.
 */
class Wood : public Materials {
private:
    int quantity;                         ///< Current quantity of wood.
    StateOfResources* state;             ///< Pointer to the current state of the wood resource.
    StateOfResources* fullState;         ///< Pointer to the FullState of the wood resource.
    StateOfResources* emptyState;        ///< Pointer to the EmptyState of the wood resource.
    StateOfResources* normalState;       ///< Pointer to the NormalState of the wood resource.

public:
    /**
     * @brief Constructs a Wood object with a specified initial state and quantity.
     * 
     * This constructor initializes the wood resource's state and quantity, 
     * and creates instances for the full, empty, and normal states.
     * 
     * @param initialState Pointer to the initial state of the wood resource.
     * @param initialQuantity The initial quantity of the wood resource.
     */
    Wood(StateOfResources* initialState, int initialQuantity);

    /**
     * @brief Uses a specified quantity of wood.
     * 
     * This method decreases the quantity of wood and updates the state based on the 
     * remaining quantity. If the quantity becomes zero or negative, the state is set to 
     * EmptyState. If it's less than the maximum capacity, it is set to NormalState; 
     * otherwise, it is set to FullState.
     * 
     * @param quantity The amount of wood to use.
     */
    void useResource(int quantity) override;

    /**
     * @brief Generates a specified quantity of wood.
     * 
     * This method increases the quantity of wood and updates the state based on the 
     * new quantity. If the quantity exceeds the maximum capacity, it is capped at that 
     * maximum, and the state is set to FullState. If it is positive but less than 
     * maximum, it is set to NormalState; if it is zero or less, it is set to EmptyState.
     * 
     * @param quantity The amount of wood to generate.
     */
    void generateResource(int quantity) override;

    /**
     * @brief Sets the state of the wood resource.
     * 
     * This method updates the current state of the wood resource to a new state.
     * 
     * @param newState Pointer to the new state to be set for the wood resource.
     */
    void setState(StateOfResources* newState);

    /**
     * @brief Gets the current quantity of wood.
     * 
     * @return The current quantity of wood.
     */
    int getQuantity() const override;

    /**
     * @brief Gets the maximum capacity of the wood resource.
     * 
     * @return The maximum capacity of wood, typically a fixed value.
     */
    int getMaxCapacity() const override;
};
