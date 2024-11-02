#include <iostream>
#include <string>

#include "Government.h"
// #include "IncomeTaxStrategy.h"
// #include "PropertyTaxStrategy.h"
// #include "SalesTaxStrategy.h"
// #include "Department.h"
// #include "TaxStrategy.h"
// #include "Bank.h"
// #include "CityGrowth.h"
// #include "Population.h"
// #include "Housing.h"
// #include "Economic.h"
// #include "Infrastructure.h"
// #include "SituationsCommand.h"
// #include "Accident.h"
// #include "Loadshedding.h"
// #include "Crime.h"
#include "Buildings.h"
#include "BuildingsUnit.h"
#include "Residential.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Landmarks.h"

using namespace std;

int main()
{
    //Instantiate Government and BuildingsUnit for constant static use
    cout << "---------Instantiate Government and BuildingsUnit---------" << endl;
    Government* globalGovern = new Government();
    BuildingsUnit* BUI = new BuildingsUnit(globalGovern);

    //Instantiate all the buildings
    cout << endl << endl << endl << "---------Instantiate all the buildings---------" << endl;
    Buildings* Res = new Residential("houses");
    Buildings* Res2 = new Residential("apartments");
    Buildings* Res3 = new Residential("estates");
    Buildings* Com = new Commercial("shops");
    Buildings* Com2 = new Commercial("offices");
    Buildings* Com3 = new Commercial("malls");
    Buildings* Ind = new Industrial("factories");
    Buildings* Ind2 = new Industrial("warehouses");
    Buildings* Ind3 = new Industrial("plants");
    Buildings* Lan = new Landmarks("parks");
    Buildings* Lan2 = new Landmarks("monuments");
    Buildings* Lan3 = new Landmarks("culturecenters");

    //Add all of the buildings
    cout << endl << "---------Add all of the buildings---------" << endl;
    cout << endl << endl << "Adding Houses: " << endl;
    BUI->add(Res);
    cout << endl << endl << "Adding Apartments: " << endl;
    BUI->add(Res2);
    cout << endl << endl << "Adding Estates: " << endl;
    BUI->add(Res3);
    cout << endl << endl << "Adding Shops: " << endl;
    BUI->add(Com);
    cout << endl << endl << "Adding Offices: " << endl;
    BUI->add(Com2);
    cout << endl << endl << "Adding Malls: " << endl;
    BUI->add(Com3);
    cout << endl << endl << "Adding Factories: " << endl;
    BUI->add(Ind);
    cout << endl << endl << "Adding Warehouses: " << endl;
    BUI->add(Ind2);
    cout << endl << endl << "Adding Plants: " << endl;
    BUI->add(Ind3);
    cout << endl << endl << "Adding Parks: " << endl;
    BUI->add(Lan);
    cout << endl << endl << "Adding Monuments: " << endl;
    BUI->add(Lan2);
    cout << endl << endl << "Adding Culturecenters: " << endl;
    BUI->add(Lan3);

    //Get Current House prices: 
    cout << endl << endl << "---------Get Current Residential Prices---------" << endl;
    BUI->getTreePrice("residential");
    cout  << "Set Residential Prices to 50" << endl;
    cout << "---------Get New Residential Prices---------" << endl;
    BUI->setTreePrice("residential", 50);


    cout << "Get child 0: "  << BUI->getChild(0)->getType() << ": " << BUI->getChild(0)->getPrice() << " money ";
    
    return 0;
}