#ifndef CITIZEN_H
#define CITIZEN_H

#include "Bank.h"

class ConcreteCitizen;

/**
 * @class Citizen
 * @brief Abstract base class representing a citizen in the transportation system.
 * 
 * This class serves as an interface for concrete implementations of citizens, 
 * providing the necessary methods to manage their attributes such as housing 
 * and employment status. Concrete subclasses must implement these virtual methods.
 */
class Citizen {
    private:
        /**
         * @brief Creates a copy of the ConcreteCitizen object.
         * 
         * This method must be implemented by derived classes to return a 
         * clone of the current ConcreteCitizen instance.
         * 
         * @return A pointer to the cloned ConcreteCitizen object.
         */
        virtual ConcreteCitizen* clone() = 0;

        /**
         * @brief Checks if the citizen has a house.
         * 
         * This method must be implemented by derived classes to indicate 
         * whether the citizen possesses a house.
         * 
         * @return True if the citizen has a house, false otherwise.
         */
        virtual bool getHouse() = 0;

        /**
         * @brief Checks if the citizen is employed.
         * 
         * This method must be implemented by derived classes to indicate 
         * whether the citizen is employed.
         * 
         * @return True if the citizen is employed, false otherwise.
         */
        virtual bool getEmployment() = 0;        
};

#endif
