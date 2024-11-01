#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Government.h"

using namespace std;

Government::Government()
{
    transportAllowed = true;
}

void Government::setTransport(bool t)
{
    transportAllowed = t;
}

void Government::cityGrow(string wh)
{
    if(wh == "population")
    {
        if(population->grow())
        {
            setStrategy(new IncomeTaxStrategy());
            randomEvent();
            currentCG = "population";
        }
    }
    else if(wh == "housing")
    {
        if(housing->grow())
        {
            setStrategy(new PropertyTaxStrategy());
            randomEvent();
            currentCG = "housing";
        }
    }
    else if(wh == "economic")
    {
        if(economic->grow())
        {
            setStrategy(new SalesTaxStrategy());
            randomEvent();
            currentCG = "economic";
        }
    }
    else if(wh == "infrastructure")
    {
        if(infrastructure->grow())
        {
            setStrategy(new PropertyTaxStrategy());
            randomEvent();
            currentCG = "infrastructure";
        }
    }
}

void Government::randomEvent()
{
    int randomValue = rand() % 21;

    SituationsCommand* accident = new Accident();
    SituationsCommand* loadshedding = new Loadshedding();
    SituationsCommand* crime = new Crime();

    if (randomValue == 8)
    {
        while(accident->execute() == false)
        {
            setTransport(false);
        }
        setTransport(true);
    }
    else if (randomValue == 13)
    {
        while(loadshedding->execute() == false)
        {
            userResource("energy");
        }
    }
    else if (randomValue == 17)
    {
        while(crime->execute() == false)
        {
            
        }
    }
}

void Government::cityShrink(string wh)
{
    if(wh == "population")
    {
        population->shrink();
        randomEvent();
    }
    else if(wh == "housing")
    {
        housing->shrink();
        randomEvent();
    }
    else if(wh == "economic")
    {
        economic->shrink();
        randomEvent();
    }
    else if(wh == "infrastructure")
    {
        infrastructure->shrink();
        randomEvent();
    }
}

void Government::setStrategy(TaxStrategy* strat)
{
    strategy = strat;
}

double Government::collectTax()
{
    if(currentCG == "population")
    {
        cityBank->increment(strategy->calculateTax((population->get() * 1500)));
        randomEvent();
    }
    else if(currentCG == "housing")
    {
        cityBank->increment(strategy->calculateTax((housing->get() * 1500)));
        randomEvent();
    }
    else if(currentCG == "economic")
    {
        cityBank->increment(strategy->calculateTax((economic->get() * 1500)));
        randomEvent();
    }
    else if(currentCG == "infrastructure")
    {
        cityBank->increment(strategy->calculateTax((infrastructure->get() * 1500)));
        randomEvent();
    }
}

void Government::cheat(string cheatCode)
{
    if(cheatCode == "weewooweewoo")
    {
        cityBank->increment(10000);
    }
}

// void Government::useResource(string wh)
// {
//     if(wh == "energy")
//     {
//         energy->useResource();
//     }
//     else if(wh == "energy")
//     {
//         energy->useResource();
//     }
//     else if(wh == "wood")
//     {
//         wood->useResource();
//     }
//     else if(wh == "steel")
//     {
//         steel->useResource();
//     }
//     else if(wh == "concrete")
//     {
//         concrete->useResource();
//     }
// }

bool Government::getTransport()
{
    return transportAllowed;
    randomEvent();
}