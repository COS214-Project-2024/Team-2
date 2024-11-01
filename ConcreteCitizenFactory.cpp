#include "ConcreteCitizenFactory.h"
#include "ConcreteCitizen.h"

ConcreteCitizen* ConcreteCitizenFactory::createCitizen(BuildingsUnit* buildings, Government* government){
    return new ConcreteCitizen(buildings, government);
}