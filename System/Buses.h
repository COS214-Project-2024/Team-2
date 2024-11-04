#ifndef BUSES_H
#define BUSES_H

#include "TransportationSystem.h"

class Bank;

/**
 * @class Buses
 * @brief Represents a bus transportation system.
 * 
 * This class inherits from TransportationSystem and provides functionality
 * for moving citizens using bus transportation.
 */
class Buses : public TransportationSystem {
    public:
        /**
         * @brief Moves a citizen using the bus transportation system.
         * 
         * This method checks if the citizen has enough funds in the bank to 
         * use the bus. If they do, it prints a success message and deducts the 
         * price of the bus fare from their bank balance. Otherwise, it informs 
         * them that they do not have enough money.
         * 
         * @param bank A pointer to the Bank object representing the citizen's bank.
         */
        void move(Bank* bank);
        
    private:
        const int speedOfVehicle = 80; ///< Speed of the bus in km/h.
        const int price = 50;          ///< Price of the bus fare in currency units.
};

#endif