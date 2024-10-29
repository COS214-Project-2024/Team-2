#ifndef CONCRETECITIZEN_H
#define CONCRETECITIZEN_H

#include "Citizen.h"

class Bank;
class TransportationSystem;

class ConcreteCitizen: public Citizen{
    private:
        Bank* bank;
        TransportationSystem* transportationSystem;

    public:
        // ConcreteCitizen(Buildings* buildings, Government* goverment);
        ConcreteCitizen();
        Citizen* clone(Citizen& other);
        bool getHouse();
        bool getEmployment();
        bool useTransport();
        void getTax(double tax);
}

#endif