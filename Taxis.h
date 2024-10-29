#ifndef TAXIS_H
#define TAXIS_H

#include "TransportationSystem.h"

class Bank;

class Taxis: public TransportationSystem{
    public:
        void move(Bank bank);
    private:
        const int speedOfVehicle = 100;
        const int price = 25;
};

#endif