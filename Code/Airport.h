#ifndef AIRPORT_H
#define AIRPORT_H

#include "TransportationSystem.h"

class Bank;

class Airport: public TransportationSystem{
    public:
        void move(Bank* bank);
    private:
        const int speedOfVehicle = 720;
        const int price = 1000;
};

#endif