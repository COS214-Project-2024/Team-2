#ifndef CONCRETECITIZENFACTORY_H
#define CONCRETECITIZENFACTORY_H

#include "CitizenFactory.h"
#include "ConcreteCitizen.h"
#include "Government.h"
#include "BuildingsUnit.h"

class BuildingsUnit;
class Government;

class ConcreteCitizenFactory : public CitizenFactory {
    public:
        ConcreteCitizen* createCitizen(BuildingsUnit* buildings, Government* goverment);
};

#endif