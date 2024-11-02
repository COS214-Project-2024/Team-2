#ifndef CONCRETECITIZENFACTORY_H
#define CONCRETECITIZENFACTORY_H

#include "CitizenFactory.h"
#include "ConcreteCitizen.h"
#include "Government.h"
#include "BuildingsUnit.h"

class BuildingsUnit;
class Government;

class ConcreteCitizenFactory : public CitizenFactory {
    private:
        BuildingsUnit* buildings;
        Government* goverment;
    public:
        ConcreteCitizenFactory(BuildingsUnit* building, Government* govermet);
        ConcreteCitizen* createCitizen();
};

#endif