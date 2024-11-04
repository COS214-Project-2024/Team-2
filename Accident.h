#ifndef ACCIDENT_H
#define ACCIDENT_H

#include "SituationsCommand.h"

/**
 * @class Accident
 * @brief Represents a command to handle accident situations in the simulation.
 *
 * This class inherits from `SituationsCommand` and provides the functionality
 * to execute a response to an accident scenario.
 */
class Accident: public SituationsCommand {
public:
    /**
     * @brief Executes the accident response command.
     * @return True if the command executed successfully, otherwise false.
     *
     * This method contains the logic to handle an accident situation within
     * the simulation.
     */
    bool execute();
};

#endif
