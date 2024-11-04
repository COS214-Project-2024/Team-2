#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Bank.h"

/**
 * @brief Represents a department in the system.
 * 
 * This class manages the satisfaction rate of citizens
 * related to the services provided by the department.
 */
class Department {
    private:
        int citizenSatisfactionRate; ///< The satisfaction rate of citizens.

    public:
        /**
         * @brief Constructs a Department object.
         * 
         * Initializes the citizen satisfaction rate to a default value.
         */
        Department();

        /**
         * @brief Retrieves the current citizen satisfaction rate.
         * 
         * @return The current satisfaction rate.
         */
        int getSatisfaction();

        /**
         * @brief Sets the citizen satisfaction rate.
         * 
         * @param level The new satisfaction level to set.
         * @param b Pointer to a Bank object used for satisfaction updates.
         */
        void setSatisfaction(int level, Bank* b);

        /**
         * @brief Destructor for the Department class.
         * 
         * Cleans up any resources used by the Department object.
         */
        ~Department();
};

#endif
