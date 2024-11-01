#ifndef CONCRETECITIZEN_H
#define CONCRETECITIZEN_H

#include "Citizen.h"

class Bank;

class ConcreteCitizen: public Citizen{
    private:
        Bank* bank;
        Buildings* buildings;
        Government* goverment;

    public:
        ConcreteCitizen(Buildings* buildings, Government* goverment);
        // ConcreteCitizen();
        Citizen* clone(Citizen& other);
        bool getHouse();
        bool getEmployment();
        bool useTransport(String transport);
        void getTax(double tax);
}

#endif