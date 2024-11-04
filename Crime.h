#ifndef CRIME_H
#define CRIME_H

#include "SituationsCommand.h"

/**
 * @brief Class representing a crime situation.
 * 
 * The Crime class inherits from the SituationsCommand class and
 * provides an implementation for handling crime-related situations.
 */
class Crime : public SituationsCommand {
    public:
        /**
         * @brief Executes the crime situation command.
         * 
         * This method defines the behavior that occurs when a crime
         * situation is executed.
         * 
         * @return true if the execution is successful, false otherwise.
         */
        bool execute();
};

#endif
