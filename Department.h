#ifndef DEPARTMENT_H
#define DEPARTMENT_H

class Department {
    private:
        int citizenSatisfactionRate;
    public:
        Department();
        int getSatisfaction();
        void setSatisfaction(int level);
        ~Department();
};

#endif