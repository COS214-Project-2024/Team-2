#ifndef TAXIS_H
#define TAXIS_H

#include "TransportationSystem.h"

class Bank;

/**
 * @brief Class representing a taxi transportation system.
 * 
 * This class is derived from the TransportationSystem base class and 
 * provides functionality for moving a taxi to a specified bank location.
 */
class Taxis : public TransportationSystem {
    public:
        /**
         * @brief Moves the taxi to the specified bank.
         * 
         * This method simulates the movement of the taxi to a given bank. 
         * It may implement the logic for updating the taxi's position and 
         * handling related actions.
         * 
         * @param bank Pointer to the Bank object representing the destination.
         */
        void move(Bank* bank);

    private:
        
        const int speedOfVehicle = 100;///< Speed of the vehicle in units per hour.
        const int price = 25;///< Price of the taxi service in monetary units.
};

#endif
