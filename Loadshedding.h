#ifndef LOADSHEDDING_H
#define LOADSHEDDING_H

#include "SituationsCommand.h"

class Loadshedding: public SituationsCommand{
    public:
        bool execute();
};

#endif
