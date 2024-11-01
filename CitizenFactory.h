#ifndef CITIZENFACTORY_H
#define CITIZENFACTORY_H

class Citizen;

class CitizenFactory{
    private:
        Citizen* createCitizen() = 0;
};

#endif