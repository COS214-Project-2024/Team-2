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

class Government
{
    private:
        Department* department = new Department();
        TaxStrategy* strategy = new IncomeTaxStrategy();
        Bank* cityBank;
        string cheatCode = "weewooweewoo";
        CityGrowth* population = new Population();
        CityGrowth* housing = new Housing();
        CityGrowth* economic = new Economic();
        CityGrowth* infrastructure = new Infrastructure();
        StateOfResources* emptyStateE = new EmptyState(energy);
        StateOfResources* emptyStateWa = new EmptyState(water);
        StateOfResources* emptyStateWo = new EmptyState(wood);
        StateOfResources* emptyStateS = new EmptyState(steel);
        StateOfResources* emptyStateC = new EmptyState(concrete);
        Energy* energy = new Energy(emptyStateE, 0);
        Water* water = new Water(emptyStateWa, 0);
        Wood* wood = new Wood(emptyStateWo, 0);
        Steel* steel = new Steel(emptyStateS, 0);
        Concrete* concrete = new Concrete(emptyStateC, 0);
        bool transportAllowed;
        string currentCG = "population";
    public:
        Government();
        void cityGrow(string who);
        void cityShrink(string who);
        void setStrategy(TaxStrategy* strat);
        double collectTax();
        void cheat(string cheatCode);
        void useResource(string who);
        bool getTransport();
        void setTransport(bool t);
        void randomEvent();
        int getSatisfaction();
        void setSatisfaction(int level);
};

#endif