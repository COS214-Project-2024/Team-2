#include "ConcreteCitizenFactory.h"
#include "Citizen.h"

Citizen* ConcreteCitizenFactory::createCitizen(Buildings* buildings, Government* goverment){
    return new Citizen(buildings, goverment);
}