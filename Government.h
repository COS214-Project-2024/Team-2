#ifndef Government_H
#define Government_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "IncomeTaxStrategy.h"
#include "PropertyTaxStrategy.h"
#include "SalesTaxStrategy.h"
#include "Department.h"
#include "TaxStrategy.h"
#include "Bank.h"
#include "CityGrowth.h"
#include "Population.h"
#include "Housing.h"
#include "Economic.h"
#include "Infrastructure.h"
#include "./Resources/Resources.h"
#include "./Resources/Materials.h"
#include "./Resources/Energy.h"
#include "./Resources/Water.h"
#include "./Resources/Wood.h"
#include "./Resources/Steel.h"
#include "./Resources/Concrete.h"
#include "./Resources/StateOfResources.h"
#include "./Resources/FullState.h"
#include "./Resources/NormalState.h"
#include "./Resources/EmptyState.h"
#include "SituationsCommand.h"
#include "Accident.h"
#include "Loadshedding.h"
#include "Crime.h"

using namespace std;

/**
 * @class Government
 * @brief Represents the government of a city, managing various resources, tax strategies, and city growth.
 */
class Government
{
private:
    Department *department = new Department();         ///< The department responsible for citizen satisfaction.
    TaxStrategy *strategy = new IncomeTaxStrategy();   ///< The current tax strategy being used.
    Bank *cityBank = new Bank();                       ///< The bank managing city finances.
    string cheatCode = "weewooweewoo";                 ///< The cheat code for special actions.
    CityGrowth *population = new Population();         ///< Represents the population growth of the city.
    CityGrowth *housing = new Housing();               ///< Represents the housing growth of the city.
    CityGrowth *economic = new Economic();             ///< Represents the economic growth of the city.
    CityGrowth *infrastructure = new Infrastructure(); ///< Represents the infrastructure growth of the city.
    // StateOfResources* emptyStateE = new EmptyState(energy);
    // StateOfResources* emptyStateWa = new EmptyState(water);
    // StateOfResources* emptyStateWo = new EmptyState(wood);
    // StateOfResources* emptyStateS = new EmptyState(steel);
    // StateOfResources* emptyStateC = new EmptyState(concrete);
    // Energy* energy = new Energy(emptyStateE, 0);
    // Water* water = new Water(emptyStateWa, 0);
    // Wood* wood = new Wood(emptyStateWo, 0);
    // Steel* steel = new Steel(emptyStateS, 0);
    // Concrete* concrete = new Concrete(emptyStateC, 0);
    Energy *energy = new Energy(nullptr, 0);       ///< Represents energy resources.
    Water *water = new Water(nullptr, 0);          ///< Represents water resources.
    Wood *wood = new Wood(nullptr, 0);             ///< Represents wood resources.
    Steel *steel = new Steel(nullptr, 0);          ///< Represents steel resources.
    Concrete *concrete = new Concrete(nullptr, 0); ///< Represents concrete resources.

    StateOfResources *emptyStateE = new EmptyState(energy);   ///< State of energy resources when empty.
    StateOfResources *emptyStateWa = new EmptyState(water);   ///< State of water resources when empty.
    StateOfResources *emptyStateWo = new EmptyState(wood);    ///< State of wood resources when empty.
    StateOfResources *emptyStateS = new EmptyState(steel);    ///< State of steel resources when empty.
    StateOfResources *emptyStateC = new EmptyState(concrete); ///< State of concrete resources when empty.

    bool transportAllowed;           ///< Indicates if transport is allowed.
    string currentCG = "population"; ///< The current city growth focus.
public:
    /**
     * @brief Constructs a Government instance.
     */
    Government();
    
    /**
     * @brief Initiates city growth based on the specified entity.
     * @param who The entity that causes the city to grow.
     */
    void cityGrow(string who);
    
    /**
     * @brief Initiates city shrinkage based on the specified entity.
     * @param who The entity that causes the city to shrink.
     */
    void cityShrink(string who);
    
    /**
     * @brief Sets the tax strategy used by the government.
     * @param strat The tax strategy to be set.
     */
    void setStrategy(TaxStrategy* strat);
    
    /**
     * @brief Collects taxes based on the current tax strategy.
     * @return The amount of tax collected.
     */
    int collectTax();
    
    /**
     * @brief Applies a cheat code for special actions.
     * @param cheatCode The cheat code to be applied.
     */
    void cheat(string cheatCode);
    
    /**
     * @brief Uses a specified resource based on the entity.
     * @param who The entity that uses the resource.
     */
    void useResource(string who);
    
    /**
     * @brief Checks if transport is allowed.
     * @return True if transport is allowed, false otherwise.
     */
    bool getTransport();
    
    /**
     * @brief Sets the transport allowed state.
     * @param t True to allow transport, false to disallow.
     */
    void setTransport(bool t);
    
    /**
     * @brief Executes a random event that affects the city.
     */
    void randomEvent();
    
    /**
     * @brief Retrieves the citizen satisfaction level.
     * @return The current satisfaction level.
     */
    int getSatisfaction();
    
    /**
     * @brief Sets the citizen satisfaction level.
     * @param level The new satisfaction level to be set.
     */
    void setSatisfaction(int level);
    
    /**
     * @brief Retrieves the current economic size.
     * @return The current economic size.
     */
    int get();
    
    /**
     * @brief Increments the economic size by a specified amount.
     * @param amount The amount to increment.
     */
    void increment(int amount);
    
    /**
     * @brief Decrements the economic size by a specified amount.
     * @param amount The amount to decrement.
     */
    void decrement(int amount);
};

#endif