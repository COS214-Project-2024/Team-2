#ifndef CONCRETECITIZEN_H
#define CONCRETECITIZEN_H

#include "Citizen.h"
#include <string>
using namespace std;

class Bank;
class BuildingsUnit;
class Government;

class ConcreteCitizen: public Citizen{
    private:
        BuildingsUnit* buildings;
        Government* government;
        bool housing = 0;
        bool employed = 0;    

    public:
        Bank* bank;
        ConcreteCitizen(BuildingsUnit* buildings, Government* government);
        ConcreteCitizen* clone();
        bool getHouse();
        bool getEmployment();
        bool useTransport(string transport);
        void getTax(int tax);
};

#endif