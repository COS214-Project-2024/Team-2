#ifndef CITIZENFACTORY_H
#define CITIZENFACTORY_H

#include "Citizen.h"
#include "ConcreteCitizen.h"

/**
 * @class CitizenFactory
 * @brief Abstract base class for creating Citizen objects.
 * 
 * This factory class defines an interface for creating ConcreteCitizen 
 * instances. Concrete implementations of this factory must provide a 
 * concrete implementation of the createCitizen method.
 */
class CitizenFactory {
    public:
        /**
         * @brief Creates a new ConcreteCitizen instance.
         * 
         * This method is a factory method that must be implemented by 
         * derived classes to create and return a new instance of 
         * ConcreteCitizen.
         * 
         * @return A pointer to the newly created ConcreteCitizen object.
         */
        virtual ConcreteCitizen* createCitizen() = 0;
};

#endif
