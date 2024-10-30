// #include<cstdlib>
#include <iostream>
using namespace std;

#include "Citizen.h"
#include "Buildings.h"
#include "Government.h"
#include "Taxis.h"
#include "Buses.h"
#include "Airport.h"
#include "Train.h"

// ConcreteCitizen::ConcreteCitizen(Buildings* buildings, Government* goverment){
ConcreteCitizen::ConcreteCitizen()
{
    Government::cityGrow("population");
    this->housing = 0;
    this->employed = 0;
    this->bank = new Bank();
}

Citizen *clone(Ciziten &other)
{
    Citizen *citizen = new Citizen();
    citizen->housing = other.housing;
    citizen->employed = other.employed;
    return citizen;
}

bool Citizen::getHouse()
{
    if (bank->budget() > 500)
    {
        vector<Buildings *>::iterator it;
        int count = 0;
        for (it = children.begin(); it != children.end(); ++it)
        {
            if (children[count]->getType() == "residential" || children[count]->getType() == "commercial")
            {
                if (!(children[count]->getTaken()))
                {
                    children[count]->setTaken(true);
                    bank->decrement(500);
                    cout << "You have bought a house." << endl;
                    return true;
                }
            }
            ++count;
        }

        cout << "There are no houses available." << endl;
        return false;
    }
    else
    {
        cout << "You do not have enough money to buy a house." << endl;
        return false;
    }
}

bool Citizen::getEmployment()
{
    vector<Buildings *>::iterator it;
        int count = 0;
        for (it = children.begin(); it != children.end(); ++it)
        {
            if (children[count]->getType() == "industrial" || children[count]->getType() == "landmarks")
            {
                if (!(children[count]->getTaken()))
                {
                    children[count]->setTaken(true);
                    bank->increment(2000);
                    cout << "You have found employment." << endl;
                    return true;
                }
            }
            ++count;
        }

    cout << "There are no employment opportunities available." << endl;
    return false;
}

bool ConcreteCitizen::useTransport(String transport)
{
    if (Government::getTransport() == false)
    {
        cout << "Sorry transportation services are not operational at this time." << endl;
        return false;
    }
    else
    {
        cout << "Transportation services are operational." << endl;

        if (transport == "Taxis")
        {
            Taxis::move(bank->budget());
        }
        else if (transport == "Buses")
        {
            Buses::move(bank->budget());
        }
        else if (transport == "Airport")
        {
            Airport::move(bank->budget());
        }
        else if (transport == "Train")
        {
            Train::move(bank->budget());
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