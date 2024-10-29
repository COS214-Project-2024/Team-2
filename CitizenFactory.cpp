#include "CitizenFactory.h"
#include "Citizen.h"

Citizen* CitizenFactory::createCitizen(){
    return new Citizen();
}