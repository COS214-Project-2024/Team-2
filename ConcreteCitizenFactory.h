#ifndef CONCRETECITIZENFACTORY_H
#define CONCRETECITIZENFACTORY_H

#include "CitizenFactory.h"

class Buildings;
class Government;

class ConcreteCitizenFactory : public CitizenFactory {
    public:
        Citizen* createCitizen(Buildings* buildings, Government* goverment);
        // bool attach(Government* goverment);
        // bool detach(Government* goverment);
};

#endif