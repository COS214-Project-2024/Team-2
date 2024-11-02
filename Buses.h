#ifndef BUSES_H
#define BUSES_H

#include "TransportationSystem.h"

class Bank;

class Buses : public TransportationSystem{
    public:
        void move(Bank* bank);
    private:
        const int speedOfVehicle = 80;
        const int price = 50;
};

#endif