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

ConcreteCitizen* ConcreteCitizen::clone()
{
    ConcreteCitizen* citizen = new ConcreteCitizen(buildings, government);
    citizen->housing = housing;
    citizen->employed = employed;
    citizen->bank = bank;
    return citizen;
}

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
        cout << "Citizen does not have enough more (Need atleast 600 money),\nCurrenlty has: " << bank->get() << " money, Consider getting an employment!" << endl;
        return false;
    }
    return false;
}

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

void ConcreteCitizen::getTax(int tax)
{
    bank->decrement(tax);
}