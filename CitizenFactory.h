#ifndef CITIZENFACTORY_H
#define CITIZENFACTORY_H

#include "Citizen.h"
#include "ConcreteCitizen.h"

class Citizen;

class CitizenFactory{
    public:
        virtual ConcreteCitizen* createCitizen() = 0;
};

#endif