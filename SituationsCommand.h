#ifndef SITUATIONSCOMMAND_H
#define SITUATIONSCOMMAND_H

/**
 * @brief Abstract base class for command situations.
 * 
 * This class defines an interface for executing commands related to different situations.
 * It contains a pure virtual function that must be implemented by derived classes.
 */
class SituationsCommand {
    public:
        /**
         * @brief Executes the command.
         * 
         * This method should be implemented by derived classes to provide
         * specific behavior for the command when executed.
         * 
         * @return true if the command was executed successfully; false otherwise.
         */
        virtual bool execute() = 0;
};

#endif
