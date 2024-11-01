#ifndef CITIZEN_H
#define CITIZEN_H

#include "Bank.h"

class ConcreteCitizen;

class Citizen{
    private:
        virtual ConcreteCitizen* clone(ConcreteCitizen& citizen) = 0;
        virtual bool getHouse() = 0;
        virtual bool getEmployment() = 0;        
};

#endif