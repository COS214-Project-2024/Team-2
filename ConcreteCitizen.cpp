#include <iostream>
using namespace std;

#include "ConcreteCitizen.h"
#include "Citizen.h"
#include "BuildingsUnit.h"
#include "Government.h"
#include "Taxis.h"
#include "Buses.h"
#include "Airport.h"
#include "Train.h"

/**
 * @brief Constructs a ConcreteCitizen with specified buildings and government.
 * 
 * This constructor initializes a ConcreteCitizen object, sets the housing 
 * and employment status to false, and creates a new Bank instance.
 * It also triggers the growth of the city's population.
 * 
 * @param buildings Pointer to the BuildingsUnit that the citizen belongs to.
 * @param government Pointer to the Government that governs the citizen.
 */
ConcreteCitizen::ConcreteCitizen(BuildingsUnit* buildings, Government* government)
{
    government->cityGrow("population");
    this->housing = 0;
    this->employed = 0;
    this->bank = new Bank();
    this->buildings = buildings;
    this->government = government;
}

/**
 * @brief Clones the ConcreteCitizen object.
 * 
 * This method creates a copy of the ConcreteCitizen object, including its 
 * housing and employment status, and bank instance.
 * 
 * @return A pointer to a new ConcreteCitizen object that is a clone of the original.
 */
ConcreteCitizen* ConcreteCitizen::clone()
{
    ConcreteCitizen* citizen = new ConcreteCitizen(buildings, government);
    citizen->housing = housing;
    citizen->employed = employed;
    citizen->bank = bank;
    return citizen;
}

/**
 * @brief Checks if the citizen can acquire housing.
 * 
 * This method checks the citizen's bank balance and the availability of 
 * housing in the buildings unit. If the citizen has enough money and a 
 * house is available, the citizen's bank is decremented and housing status 
 * is set to true.
 * 
 * @return true if the citizen successfully acquires housing, false otherwise.
 */
bool ConcreteCitizen::getHouse()
{
    if(bank->get() >= 600)
    {
        if(this->buildings->getHouse())
        {
            cout << "Citizen Has Gotten a House " << endl;
        }
        bank->decrement(500);
        return true;
    }
    else
    {
        cout << "Citizen does not have enough money (Need at least 600 money),\nCurrently has: " << bank->get() << " money. Consider getting employment!" << endl;
        return false;
    }
    return false;
}

/**
 * @brief Checks if the citizen can acquire employment.
 * 
 * This method checks the availability of employment in the buildings unit. 
 * If employment is available, the citizen's bank is incremented, and the 
 * employment status is set to true.
 * 
 * @return true if the citizen successfully acquires employment, false otherwise.
 */
bool ConcreteCitizen::getEmployment()
{
    if(this->buildings->getEmployment())
    {
        cout << "Citizen Has Gotten an Employment " << endl;
        bank->increment(600);
        cout << "Currently has: " << bank->get() << " money" << endl;
        return true;
    }
    return false;
}

/**
 * @brief Uses a specified mode of transportation.
 * 
 * This method checks if the transportation services are operational and 
 * attempts to use the specified transport method (Taxis, Buses, Airport, 
 * or Train) to travel. If the transport type is invalid, an error message 
 * is displayed.
 * 
 * @param transport A string indicating the mode of transport to use.
 * @return true if the transportation was successful, false otherwise.
 */
bool ConcreteCitizen::useTransport(string transport)
{
    if (government->getTransport() == false)
    {
        cout << "Sorry, transportation services are not operational at this time." << endl;
        return false;
    }
    else
    {
        cout << "Transportation services are operational." << endl;

        if (transport == "Taxis")
        {
            Taxis* taxis = new Taxis();
            taxis->move(this->bank);
        }
        else if (transport == "Buses")
        {
            Buses* buses = new Buses();
            buses->move(this->bank);
        }
        else if (transport == "Airport")
        {
            Airport* airport = new Airport();
            airport->move(this->bank);
        }
        else if (transport == "Train")
        {
            Train* train = new Train();
            train->move(this->bank);
        }
        else
        {
            cout << "Invalid transport type.\nThe transportation services are; 'Taxis', 'Buses', 'Airport', and 'Train'." << endl;
            return false;
        }

        return true;
    }
}

/**
 * @brief Applies tax to the citizen.
 * 
 * This method deducts the specified tax amount from the citizen's bank account.
 * 
 * @param tax The amount of tax to be deducted.
 */
void ConcreteCitizen::getTax(int tax)
{
    bank->decrement(tax);
}
