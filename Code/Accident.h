#ifndef ACCIDENT_H
#define ACCIDENT_H

#include "SituationsCommand.h"

class Accident: public SituationsCommand{
    public:
        bool execute();
};

#endif