#include "ConcreteCitizenFactory.h"
#include "ConcreteCitizen.h"

Citizen* ConcreteCitizenFactory::createCitizen(Buildings* buildings, Government* goverment){
    return new Citizen(buildings, goverment);
}

// Citizen* ConcreteCitizenFactory::createCitizen(){
//     return new Citizen();
// }