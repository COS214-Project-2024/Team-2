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
#include "Resources.h"
#include "Materials.h"
#include "Energy.h"
#include "Water.h"
#include "Wood.h"
#include "Steel.h"
#include "Concrete.h"
#include "StateOfResources.h"
#include "FullState.h"
#include "NormalState.h"
#include "EmptyState.h"

using namespace std;

class Government
{
    private:
        Department* department;
        TaxStrategy* strategy = new IncomeTaxStrategy();
        Bank* cityBank;
        string cheatCode = "weewooweewoo";
        CityGrowth* population = new Population();
        CityGrowth* housing = new Housing();
        CityGrowth* economic = new Economic();
        CityGrowth* infrastructure = new Infrastructure();
        Resources* energy = new Energy();
        Resources* water = new Water();
        Resources* wood = new Wood();
        Resources* steel = new Steel();
        Resources* concrete = new Concrete();
        bool transportAllowed = true;
        string currentCG = "population";
    public:
        Government()
        void cityGrow(string who);
        void cityShrink(string who);
        void setStrategy(TaxStrategy* strat);
        double collectTax();
        void cheat(string cheatCode);
        void userResource(string who);
        bool getTransport();
        void setTranposrt(bool t);
};

#endif