#include "ConcreteCitizenFactory.h"

ConcreteCitizenFactory::ConcreteCitizenFactory(BuildingsUnit* b, Government* g)
{
    buildings = b;
    government = g;
}

ConcreteCitizen* ConcreteCitizenFactory::createCitizen()
{
    return new ConcreteCitizen(buildings, government);
}