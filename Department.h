#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Bank.h"

class Department {
    private:
        int citizenSatisfactionRate;
    public:
        Department();
        int getSatisfaction();
        void setSatisfaction(int level, Bank* b);
        ~Department();
};

#endif