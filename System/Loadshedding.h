#ifndef LOADSHEDDING_H
#define LOADSHEDDING_H

#include "SituationsCommand.h"

/**
 * @brief Class representing a load shedding command.
 * 
 * The Loadshedding class is derived from the SituationsCommand class
 * and implements the execute method to handle load shedding situations
 * in the city.
 */
class Loadshedding : public SituationsCommand {
    public:
        /**
         * @brief Executes the load shedding command.
         * 
         * This method contains the logic to be executed when a load shedding 
         * situation arises. The specifics of this execution are defined in 
         * the method implementation.
         * 
         * @return true if the command executed successfully, false otherwise.
         */
        bool execute();
};

#endif
