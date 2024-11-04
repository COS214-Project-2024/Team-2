#ifndef CONCRETECITIZENFACTORY_H
#define CONCRETECITIZENFACTORY_H

#include "CitizenFactory.h"
#include "ConcreteCitizen.h"
#include "Government.h"
#include "BuildingsUnit.h"

class BuildingsUnit;
class Government;

/**
 * @brief A factory class for creating ConcreteCitizen instances.
 * 
 * This class implements the CitizenFactory interface and is responsible 
 * for creating ConcreteCitizen objects, providing a way to create citizens 
 * associated with specific buildings and government.
 */
class ConcreteCitizenFactory : public CitizenFactory {
    private:
        BuildingsUnit* buildings; ///< Pointer to the BuildingsUnit associated with the citizens.
        Government* government;    ///< Pointer to the Government associated with the citizens.

    public:
        /**
         * @brief Constructs a ConcreteCitizenFactory with specified buildings and government.
         * 
         * @param building Pointer to the BuildingsUnit that citizens will be associated with.
         * @param government Pointer to the Government that governs the citizens.
         */
        ConcreteCitizenFactory(BuildingsUnit* building, Government* government);

        /**
         * @brief Creates a new ConcreteCitizen instance.
         * 
         * This method creates a ConcreteCitizen object associated with the 
         * specified BuildingsUnit and Government.
         * 
         * @return A pointer to a newly created ConcreteCitizen object.
         */
        ConcreteCitizen* createCitizen();
};

#endif
