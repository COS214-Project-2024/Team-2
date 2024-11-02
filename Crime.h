#ifndef CRIME_H
#define CRIME_H

#include "SituationsCommand.h"

class Crime: public SituationsCommand{
    public:
        bool execute();
};

#endif