#include "ConcreteCitizenFactory.h"

ConcreteCitizen* ConcreteCitizenFactory::createCitizen(BuildingsUnit* buildings, Government* government){
    return new ConcreteCitizen(buildings, government);
}