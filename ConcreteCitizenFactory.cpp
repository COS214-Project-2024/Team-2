#include "ConcreteCitizenFactory.h"

/**
 * @brief Constructs a ConcreteCitizenFactory with specified buildings and government.
 * 
 * @param b Pointer to the BuildingsUnit that citizens will be associated with.
 * @param g Pointer to the Government that governs the citizens.
 */
ConcreteCitizenFactory::ConcreteCitizenFactory(BuildingsUnit* b, Government* g)
{
    buildings = b;
    government = g;
}

/**
 * @brief Creates a new ConcreteCitizen instance.
 * 
 * This method instantiates a ConcreteCitizen object associated with the 
 * BuildingsUnit and Government provided during the factory's construction.
 * 
 * @return A pointer to a newly created ConcreteCitizen object.
 */
ConcreteCitizen* ConcreteCitizenFactory::createCitizen()
{
    return new ConcreteCitizen(buildings, government);
}
