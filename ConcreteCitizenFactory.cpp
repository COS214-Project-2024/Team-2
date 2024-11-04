#include "ConcreteCitizenFactory.h"

ConcreteCitizenFactory::ConcreteCitizenFactory(BuildingsUnit* b, Government* g)
{
    buildings = b;
    goverment = g;
}

ConcreteCitizen* ConcreteCitizenFactory::createCitizen()
{
    return new ConcreteCitizen(buildings, goverment);
}