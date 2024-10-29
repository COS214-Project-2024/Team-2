#include <iostream>
#include <string>

#include "Bank.h"
#include "CityGrowth.h"
#include "TaxStrategy.h"

#include "IncomeTaxStrategy.h"
#include "PropertyTaxStrategy.h"
#include "SalesTaxStrategy.h"
#include "Population.h"
#include "Housing.h"
#include "Economic.h"
#include "Infrastructure.h"

using namespace std;

// Global variables
CityGrowth* population = new Population();
CityGrowth* housing = new Housing();
CityGrowth* economic = new Economic();
CityGrowth* infrastructure = new Infrastructure();
TaxStrategy* strategy = nullptr;
string currentCG;
Bank* cityBank = new Bank();

void cityGrow(string wh);
double collectTax();
void setStrategy(TaxStrategy* strat);
void cityShrink(string wh);

int main()
{
    cout << "Bank before: " << cityBank->get() << endl;
    cityGrow("population");
    cout << "Population: " << population->get() << endl;
    cityGrow("population");
    cout << "Population: " << population->get() << endl;
    cityGrow("population");
    cout << "Population: " << population->get() << endl;
    cityGrow("population");
    cout << "Population: " << population->get() << endl;
    cityGrow("population");
    cout << "Population: " << population->get() << endl;
    cityGrow("population");
    cout << "Population: " << population->get() << endl;
    cityGrow("population");
    cout << "Population: " << population->get() << endl;
    cityGrow("population");
    cout << "Population: " << population->get() << endl;
    cityGrow("population");
    cout << "Population: " << population->get() << endl;
    cityShrink("population");
    cout << "Population: " << population->get() << endl;
    collectTax();
    cout << "Bank after: " << cityBank->get() << endl;
    
    delete population;
    delete housing;
    delete economic;
    delete infrastructure;
    delete strategy;

    return 0;
}

void cityGrow(string wh)
{
    if (wh == "population")
    {
        cout << "here" << endl;
        if (population->grow())
        {
            delete strategy; // Clean up previous strategy if any
            strategy = new IncomeTaxStrategy(); // Allocate new strategy
            currentCG = "population";
            cout << "Pop size grow: " << population->get() << endl;
        }
    }
    else if (wh == "housing")
    {
        if (housing->grow())
        {
            delete strategy; // Clean up previous strategy if any
            strategy = new PropertyTaxStrategy();
            currentCG = "housing";
        }
    }
    else if (wh == "economic")
    {
        if (economic->grow())
        {
            delete strategy; // Clean up previous strategy if any
            strategy = new SalesTaxStrategy();
            currentCG = "economic";
        }
    }
    else if (wh == "infrastructure")
    {
        if (infrastructure->grow())
        {
            delete strategy; // Clean up previous strategy if any
            strategy = new PropertyTaxStrategy();
            currentCG = "infrastructure";
        }
    }
}

void cityShrink(string wh)
{
    if(wh == "population")
    {
        population->shrink();
        cout << "pop size shink: " << population->get() << endl;
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

void setStrategy(TaxStrategy* strat)
{
    strategy = strat;
}

double collectTax()
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
