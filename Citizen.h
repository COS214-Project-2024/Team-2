#ifndef CITIZEN_H
#define CITIZEN_H

#include "Bank.h"

class Buildings;
class Government;

class Citizen{
    private:
        bool employed;
        bool housing;
        Citizen* clone(Citizen& citizen) = 0;
        bool getHouse() = 0;
        bool getEmployment() = 0;
};

#endif