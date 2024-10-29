// #include<cstdlib>
#include <iostream>
using namespace std;

#include "Citizen.h"
#include "Buildings.h"
#include "Government.h"
#include "TransportationSystem.h"


ConcreteCitizen::ConcreteCitizen(Buildings* buildings, Government* goverment){
    Government::cityGrow("population");
    this->housing = 0;
    this->employed = 0;
    this->bank = new Bank();
}

Citizen* clone(Ciziten& other){
    Citizen* citizen = new Citizen();
    citizen->housing = other.housing;
    citizen->employed = other.employed;
    return citizen;
}

bool Citizen::getHouse()
{
    std::vector<Buildings*>::iterator it;
    int count = 0;
    for(it = children.begin(); it != children.end(); ++it) 
    {
        if(children[count]->getType() == "residential" || children[count]->getType() == "commercial") 
        {
            if(!(children[count]->getTaken())) 
            {
                children[count]->setTaken(true);
                return true;
            }
        }
        ++count;
    }

    return false;
}

bool Citizen::getEmployment()
{
    std::vector<Buildings*>::iterator it;
    int count = 0;
    for(it = children.begin(); it != children.end(); ++it) 
    {
        if(children[count]->getType() == "industrial" || children[count]->getType() == "landmarks") 
        {
            if(!(children[count]->getTaken())) 
            {
                children[count]->setTaken(true);
                return true;
            }
        }
        ++count;
    }

    return false;
}

bool ConcreteCitizen::useTransport()
{
    TransportationSystem::move(bank->budget());
}