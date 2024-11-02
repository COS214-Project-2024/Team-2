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

ConcreteCitizen::ConcreteCitizen(BuildingsUnit* buildings, Government* government)
{
    government->cityGrow("population");
    this->housing = 0;
    this->employed = 0;
    this->bank = new Bank();
    this->buildings = buildings;
    this->government = government;
}

ConcreteCitizen* ConcreteCitizen::clone(ConcreteCitizen &other)
{
    ConcreteCitizen* citizen = new ConcreteCitizen(other.buildings, other.government);
    citizen->housing = other.housing;
    citizen->employed = other.employed;
    citizen->bank = other.bank;
    return citizen;
}

bool ConcreteCitizen::getHouse()
{
    this->buildings->getHouse();
}

bool ConcreteCitizen::getEmployment()
{
    this->buildings->getEmployment();
}

bool ConcreteCitizen::useTransport(string transport)
{
    if (government->getTransport() == false)
    {
        cout << "Sorry transportation services are not operational at this time." << endl;
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
            cout << "Invalid transport type.\nThe transportation services are; 'Taxis', 'Buses', 'Airport' and 'Train'." << endl;
            return false;
        }

        return true;
    }
}

void ConcreteCitizen::getTax(double tax)
{
    bank->decrement(tax);
}