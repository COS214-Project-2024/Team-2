#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Government.h"

using namespace std;

/**
 * @brief Constructs a Government object, initializes resources and bank balance.
 * 
 * This constructor sets the initial state for the government, including 
 * transport permission, initializes the city bank with a starting amount, 
 * and sets the states of various resources to their empty states. It also 
 * generates an initial quantity of each resource.
 */
Government::Government()
{
    transportAllowed = true;
    cityBank->increment(2000);
    cout << "Your current bank: " << cityBank->get() << " money" << endl;
    energy->setState(emptyStateE);
    water->setState(emptyStateWa);
    wood->setState(emptyStateWo);
    steel->setState(emptyStateS);
    concrete->setState(emptyStateC);
    energy->generateResource(100);
    water->generateResource(100);
    wood->generateResource(100);
    steel->generateResource(100);
    concrete->generateResource(100);
}

/**
 * @brief Gets the current amount of money in the city's bank.
 * 
 * @return The current bank balance.
 */
int Government::get()
{
    return cityBank->get();
}

/**
 * @brief Increments the bank balance by a specified amount.
 * 
 * @param amount The amount to add to the bank balance.
 */
void Government::increment(int amount)
{
    cityBank->increment(amount);
}

/**
 * @brief Decrements the bank balance by a specified amount.
 * 
 * @param amount The amount to subtract from the bank balance.
 */
void Government::decrement(int amount)
{
    cityBank->decrement(amount);
}

/**
 * @brief Sets whether transport is allowed or not.
 * 
 * @param t Boolean indicating if transport is allowed.
 */
void Government::setTransport(bool t)
{
    transportAllowed = t;
    cout << "Transport is set to: " << transportAllowed << endl;
}

/**
 * @brief Handles city growth based on the specified category.
 * 
 * The city can grow in various categories: population, residential, 
 * commercial, industrial, and infrastructure. Each category has its 
 * associated growth strategy and updates citizen satisfaction.
 * 
 * @param wh The category of growth (e.g., "population", "residential").
 */
void Government::cityGrow(string wh)
{
    if(wh == "population")
    {
        cout << "Population grew" << endl;
        if(population->grow())
        {
            cout << "Current Population is: " << population->get() << endl;
            int satisTemp = getSatisfaction();
            satisTemp = satisTemp + 1;
            cout << endl << "citizen Satisfaction went up by 1" << endl;
            setSatisfaction(satisTemp);
            setStrategy(new IncomeTaxStrategy());
            cout << "Strategy setted to: IncomeTaxStrategy" << endl;
            randomEvent();
            currentCG = "population";
        }
    }
    else if(wh == "residential")
    {
        cout << "Housing grew" << endl;
        if(housing->grow())
        {
            cout << "Current Residential Size is: " << housing->get() << endl;
            int satisTemp = getSatisfaction();
            satisTemp = satisTemp + 1;
            cout << endl << "citizen Satisfaction went up by 1" << endl;
            setSatisfaction(satisTemp);
            setStrategy(new PropertyTaxStrategy());
            cout << "Strategy setted to: PropertyTaxStrategy" << endl;
            randomEvent();
            currentCG = "housing";
        }
    }
    else if(wh == "commercial" || wh == "industrial")
    {
        cout << "Economic grew" << endl;
        if(economic->grow())
        {
            cout << "Current Economic Size is: " << economic->get() << endl;
            int satisTemp = getSatisfaction();
            satisTemp = satisTemp + 1;
            cout << endl << "citizen Satisfaction went up by 1" << endl;
            setSatisfaction(satisTemp);
            setStrategy(new SalesTaxStrategy());
            cout << "Strategy setted to: SalesTaxStrategy" << endl;
            randomEvent();
            currentCG = "economic";
        }
    }
    else if(wh == "landmarks")
    {
        cout << "Infrastructure grew" << endl;
        if(infrastructure->grow())
        {
            cout << "Current Infrastructure Size is: " << infrastructure->get() << endl;
            int satisTemp = getSatisfaction();
            satisTemp = satisTemp + 1;
            cout << endl << "citizen Satisfaction went up by 1" << endl;
            setSatisfaction(satisTemp);
            setStrategy(new PropertyTaxStrategy());
            cout << "Strategy setted to: PropertyTaxStrategy" << endl;
            randomEvent();
            currentCG = "infrastructure";
        }
    }
}

/**
 * @brief Handles a random event that may affect citizen satisfaction.
 * 
 * The method randomly selects an event (accident, loadshedding, or crime) 
 * and executes it, potentially reducing the citizen satisfaction.
 */
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
            int sitTemp = department->getSatisfaction();
            sitTemp = sitTemp - 1;
            cout << "citizen Satisfaction dropped by 1" << endl;
            department->setSatisfaction(sitTemp, cityBank);
        }
        int sitTemp = department->getSatisfaction();
        sitTemp = sitTemp - 1;
        cout << "citizen Satisfaction dropped by 1" << endl;
        department->setSatisfaction(sitTemp, cityBank);
        setTransport(true);
        cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
    }
    else if (randomValue == 13)
    {
        while(loadshedding->execute() == false)
        {
            useResource("energy");
            int sitTemp = department->getSatisfaction();
            sitTemp = sitTemp - 1;
            cout << "citizen Satisfaction dropped by 1" << endl;
            department->setSatisfaction(sitTemp, cityBank);
        }
        int sitTemp = department->getSatisfaction();
        sitTemp = sitTemp - 1;
        cout << "citizen Satisfaction dropped by 1" << endl;
        department->setSatisfaction(sitTemp, cityBank);
        cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
    }
    else if (randomValue == 17)
    {
        while(crime->execute() == false)
        {
            int sitTemp = department->getSatisfaction();
            sitTemp = sitTemp - 1;
            cout << "citizen Satisfaction dropped by 1" << endl;
            department->setSatisfaction(sitTemp, cityBank);
        }
        int sitTemp = department->getSatisfaction();
        sitTemp = sitTemp - 1;
        cout << "citizen Satisfaction dropped by 1" << endl;
        department->setSatisfaction(sitTemp, cityBank);
        cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
    }
}

/**
 * @brief Handles city shrinkage based on the specified category.
 * 
 * The city can shrink in various categories: population, housing, 
 * economic, and infrastructure. Each category reduces its size and 
 * triggers a random event.
 * 
 * @param wh The category of shrinkage (e.g., "population", "housing").
 */
void Government::cityShrink(string wh)
{
    if(wh == "population")
    {
        population->shrink();
        cout << "Population shrank" << endl;
        cout << "Current population is: " << population->get() << endl;
        randomEvent();
    }
    else if(wh == "housing")
    {
        housing->shrink();
        cout << "Housing shrank" << endl;
        cout << "Current population is: " << housing->get() << endl;
        randomEvent();
    }
    else if(wh == "economic")
    {
        economic->shrink();
        cout << "Economic shrank" << endl;
        cout << "Current population is: " << economic->get() << endl;
        randomEvent();
    }
    else if(wh == "infrastructure")
    {
        infrastructure->shrink();
        cout << "Infrastructure shrank" << endl;
        cout << "Current population is: " << infrastructure->get() << endl;
        randomEvent();
    }
}

/**
 * @brief Sets the tax strategy to be used for tax collection.
 * 
 * @param strat Pointer to the TaxStrategy to be set.
 */
void Government::setStrategy(TaxStrategy* strat)
{
    strategy = strat;
}

/**
 * @brief Collects taxes based on the current growth category.
 * 
 * The method calculates and collects taxes using the current tax strategy 
 * for the relevant growth category (population, housing, economic, or 
 * infrastructure).
 * 
 * @return The amount of tax collected.
 */
int Government::collectTax()
{
    if(currentCG == "population")
    {
        cout << "Collecting taxes: " << endl;
        cityBank->increment(strategy->calculateTax((population->get() * 1500)));
        cout << "Your current bank: " << cityBank->get() << " money" << endl;
        randomEvent();
        return strategy->calculateTax(population->get() * 1500);
    }
    else if(currentCG == "housing")
    {
        cout << "Collecting taxes: " << endl;
        cityBank->increment(strategy->calculateTax((housing->get() * 1500)));
        cout << "Your current bank: " << cityBank->get() << " money" << endl;
        randomEvent();
        return strategy->calculateTax(population->get() * 1500);
    }
    else if(currentCG == "economic")
    {
        cout << "Collecting taxes: " << endl;
        cityBank->increment(strategy->calculateTax((economic->get() * 1500)));
        cout << "Your current bank: " << cityBank->get() << " money" << endl;
        randomEvent();
        return strategy->calculateTax(population->get() * 1500);
    }
    else if(currentCG == "infrastructure")
    {
        cout << "Collecting taxes: " << endl;
        cityBank->increment(strategy->calculateTax((infrastructure->get() * 1500)));
        cout << "Your current bank: " << cityBank->get() << " money" << endl;
        randomEvent();
        return strategy->calculateTax(population->get() * 1500);
    }
}

/**
 * @brief Applies a cheat code for special actions.
 * 
 * The method checks if the cheat code is valid and, if so, applies the 
 * cheat code to the city bank balance.
 * 
 * @param cheatCode The cheat code to be applied.
 */
void Government::cheat(string cheatCode)
{
    if(cheatCode == "weewooweewoo")
    {
        cout << "Cheat code succesfull, we'll keep this a secret... ;P" << endl;
        cityBank->increment(20000);
    }
}

/**
 * @brief Uses a specified resource and updates the resource state accordingly.
 * 
 * The method attempts to use a resource (energy, water, wood, steel, or 
 * concrete). If the resource state is not empty, it decrements the resource 
 * amount; otherwise, it generates an error message.
 * 
 * @param resource The name of the resource to use.
 */
void Government::useResource(string wh)
{
    if(wh == "energy")
    {
        cout << "5: Powerplant calls for ENERGY to be made and used" << endl;
        energy->useResource(20);
        if(energy->getQuantity() == 0)
        {
            energy->generateResource(100);
        }
    }
    else if(wh == "water")
    {
        cout << "4: WaterSupply calls for WATER to be made and used" << endl;
        water->useResource(20);
        if(water->getQuantity() == 0)
        {
            water->generateResource(100);
        }
    }
    else if(wh == "wood")
    {
        cout << "2: MaterialFactory calls for WOOD to be made and used" << endl;
        wood->useResource(20);
        if(wood->getQuantity() == 0)
        {
            wood->generateResource(100);
        }
    }
    else if(wh == "steel")
    {
        cout << "1: MaterialFactory calls for STEEL to be made and used" << endl;
        steel->useResource(20);
        if(steel->getQuantity() == 0)
        {
            steel->generateResource(100);
        }
    }
    else if(wh == "concrete")
    {
        cout << "3: MaterialFactory calls for CONCRETE to be made and used" << endl;
        concrete->useResource(20);
        if(concrete->getQuantity() == 0)
        {
            concrete->generateResource(100);
        }
    }
}

/**
 * @brief Checks if transport is allowed.
 * 
 * @return True if transport is allowed, false otherwise.
 */
bool Government::getTransport()
{
    randomEvent();
    return transportAllowed;
}

/**
 * @brief Gets the current citizen satisfaction level.
 * 
 * @return The current citizen satisfaction level.
 */
int Government::getSatisfaction()
{
    return department->getSatisfaction();
}

/**
 * @brief Sets the citizen satisfaction level.
 * 
 * @param sat The new citizen satisfaction level to set.
 */
void Government::setSatisfaction(int lvl)
{
    department->setSatisfaction(lvl, cityBank);
}