#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Government.h"

using namespace std;

void Government::cityGrow(string wh)
{
    if(wh == "population")
    {
        if(population->grow())
        {
            strategy->setStrategy(new IncomeTaxStrategy());
            currentCG = "population";
        }
    }
    else if(wh == "housing")
    {
        if(housing->grow())
        {
            strategy->setStrategy(new PropertyTaxStrategy());
            currentCG = "housing";
        }
    }
    else if(wh == "economic")
    {
        if(economic->grow())
        {
            strategy->setStrategy(new SalesTaxStrategy());
            currentCG = "economic";
        }
    }
    else if(wh == "infrastructure")
    {
        if(infrastructure->grow())
        {
            strategy->setStrategy(new PropertyTaxStrategy());
            currentCG = "infrastructure";
        }
    }
}

void Government::cityShrink(string wh)
{
    if(wh == "population")
    {
        population->shrink();
    }
    else if(wh == "housing")
    {
        housing->shrink();
    }
    else if(wh == "economic")
    {
        economic->shrink();
    }
    else if(wh == "infrastructure")
    {
        infrastructure->shrink();
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
    }
    else if(currentCG == "housing")
    {
        cityBank->increment(strategy->calculateTax((housing->get() * 1500)));
    }
    else if(currentCG == "economic")
    {
        cityBank->increment(strategy->calculateTax((economic->get() * 1500)));
    }
    else if(currentCG == "infrastructure")
    {
        cityBank->increment(strategy->calculateTax((infrastructure->get() * 1500)));
    }
}

void Government::cheat(string cheatCode)
{
    if(cheatCode == "weewooweewoo")
    {
        cityBank->increment(10000);
    }
}

void Government::useResource(string wh)
{
    if(wh == "energy")
    {
        energy->useResource();
    }
    else if(wh == "energy")
    {
        energy->useResource();
    }
    else if(wh == "wood")
    {
        wood->useResource();
    }
    else if(wh == "steel")
    {
        steel->useResource();
    }
    else if(wh == "concrete")
    {
        concrete->useResource();
    }
}

bool Government::getTransport()
{
    return transportAllowed;
}

void Government::setTransport(bool t)
{
    transportAllowed = t;
}