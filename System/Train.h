#ifndef TRAIN_H
#define TRAIN_H

#include "TransportationSystem.h"

class Bank;

/**
 * @class Train
 * @brief Class representing a train transportation system.
 * 
 * This class extends the TransportationSystem and provides an implementation
 * for moving citizens using train transportation. It includes information
 * about the speed and cost associated with the train.
 */
class Train: public TransportationSystem{
    public:
        /**
         * @brief Moves a citizen using the train if they can afford the fare.
         * 
         * This function checks the bank balance of the citizen. If the balance
         * is greater than the train fare, the citizen will use the train for
         * transportation. Otherwise, a message indicating insufficient funds is displayed.
         * 
         * @param bank A pointer to the Bank object that contains the citizen's bank balance.
         */
        void move(Bank* bank);
        
    private:
        const int speedOfVehicle = 180; ///< The maximum speed of the train in km/h.
        const int price = 100; ///< The fare for using the train.
};

#endif
