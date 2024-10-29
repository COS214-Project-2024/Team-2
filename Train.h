#ifndef TRAIN_H
#define TRAIN_H

#include "TransportationSystem.h"

class Bank;

class Train: public TransportationSystem{
    public:
        void move(Bank bank);
    private:
        const int speedOfVehicle = 180;
        const int price = 100;
};

#endif