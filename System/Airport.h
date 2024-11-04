#ifndef AIRPORT_H
#define AIRPORT_H

#include "TransportationSystem.h"

class Bank;

/**
 * @brief Represents an airport transportation system.
 * 
 * The Airport class inherits from TransportationSystem and provides the functionality
 * for citizens to use airport transportation if they have sufficient funds.
 */
class Airport : public TransportationSystem {
    public:
        /**
         * @brief Moves a citizen using airport transportation.
         * 
         * This method checks if the citizen (represented by a Bank object) has sufficient
         * funds to use the airport. If so, the citizen uses the airport transportation,
         * and the required amount is deducted from their account.
         * 
         * @param bank A pointer to the Bank instance representing the citizen's funds.
         */
        void move(Bank* bank);

    private:
        const int speedOfVehicle = 720; /**< The speed of the airport transportation vehicle in km/h */
        const int price = 1000; /**< The price required to use the airport transportation */
};

#endif
