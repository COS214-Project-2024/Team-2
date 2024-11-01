#include "Department.h"

Department::Department() {
    this->citizenSatisfactionRate = 0;
}

int Department::getSatisfaction() {
    return this->citizenSatisfactionRate;
}

void Department::setSatisfaction(int level) {
    this->citizenSatisfactionRate = level;
}