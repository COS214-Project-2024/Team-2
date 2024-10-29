#ifndef CITIZEN_H
#define CITIZEN_H

class Citizen{
    private:
        Citizen* clone(Citizen& citizen);
        bool getHouse();
        bool getEmployment();
};

#endif