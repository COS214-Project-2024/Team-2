#ifndef CONCRETECITIZEN_H
#define CONCRETECITIZEN_H

#include "Citizen.h"
#include <string>

using namespace std;

class Bank;
class BuildingsUnit;
class Government;

/**
 * @brief Represents a concrete implementation of a Citizen.
 * 
 * This class holds the attributes and behaviors of a citizen within the 
 * transportation and economic system, including housing and employment 
 * status, as well as interactions with buildings and government.
 */
class ConcreteCitizen : public Citizen {
private:
    BuildingsUnit* buildings; ///< Pointer to the BuildingsUnit associated with the citizen.
    Government* government; ///< Pointer to the Government associated with the citizen.
    bool housing = 0; ///< Indicates if the citizen has housing.
    bool employed = 0; ///< Indicates if the citizen is employed.

public:
    Bank* bank; ///< Pointer to the Bank associated with the citizen.

    /**
     * @brief Constructs a ConcreteCitizen with specified buildings and government.
     * 
     * This constructor initializes a ConcreteCitizen object with the provided 
     * buildings unit and government.
     * 
     * @param buildings Pointer to the BuildingsUnit that the citizen belongs to.
     * @param government Pointer to the Government that governs the citizen.
     */
    ConcreteCitizen(BuildingsUnit* buildings, Government* government);

    /**
     * @brief Clones the ConcreteCitizen object.
     * 
     * This method creates a copy of the ConcreteCitizen object.
     * 
     * @return A pointer to a new ConcreteCitizen object that is a clone of the original.
     */
    ConcreteCitizen* clone();

    /**
     * @brief Checks if the citizen has housing.
     * 
     * This method returns the housing status of the citizen.
     * 
     * @return true if the citizen has housing, false otherwise.
     */
    bool getHouse();

    /**
     * @brief Checks if the citizen is employed.
     * 
     * This method returns the employment status of the citizen.
     * 
     * @return true if the citizen is employed, false otherwise.
     */
    bool getEmployment();

    /**
     * @brief Uses a specified mode of transportation.
     * 
     * This method allows the citizen to use the specified transport method.
     * 
     * @param transport A string indicating the mode of transport to use.
     * @return true if the transportation was successful, false otherwise.
     */
    bool useTransport(string transport);

    /**
     * @brief Applies tax to the citizen.
     * 
     * This method deducts the specified tax amount from the citizen's bank account.
     * 
     * @param tax The amount of tax to be deducted.
     */
    void getTax(int tax);
};

#endif
