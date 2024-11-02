#ifndef CONCRETECITIZENFACTORY_H
#define CONCRETECITIZENFACTORY_H

#include "CitizenFactory.h"

class BuildingsUnit;
class Government;

class ConcreteCitizenFactory : public CitizenFactory {
    public:
        ConcreteCitizen* createCitizen(BuildingsUnit* buildings, Government* goverment);
};

#endif