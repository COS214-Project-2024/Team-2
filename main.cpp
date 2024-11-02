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
#include "Citizen.h"
#include "CitizenFactory.h"
#include "ConcreteCitizen.h"
#include "ConcreteCitizenFactory.h"

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

    //Print Tree of Buildings
    cout << endl << endl << "---------Print Current Tree of Buildings---------" << endl;
    cout << "Get child 0: "  << BUI->getChild(0)->getType() << ": " << BUI->getChild(0)->getPrice() << " money " << "Taken: " << BUI->getChild(0)->getTaken() << endl;
    cout << "Get child 1: "  << BUI->getChild(1)->getType() << ": " << BUI->getChild(1)->getPrice() << " money " << "Taken: " << BUI->getChild(1)->getTaken() << endl;
    cout << "Get child 2: "  << BUI->getChild(2)->getType() << ": " << BUI->getChild(2)->getPrice() << " money " << "Taken: " << BUI->getChild(2)->getTaken() << endl;
    cout << "Get child 3: "  << BUI->getChild(3)->getType() << ": " << BUI->getChild(3)->getPrice() << " money " << "Taken: " << BUI->getChild(3)->getTaken() << endl;
    cout << "Get child 4: "  << BUI->getChild(4)->getType() << ": " << BUI->getChild(4)->getPrice() << " money " << "Taken: " << BUI->getChild(4)->getTaken() << endl;
    cout << "Get child 5: "  << BUI->getChild(5)->getType() << ": " << BUI->getChild(5)->getPrice() << " money " << "Taken: " << BUI->getChild(5)->getTaken() << endl;
    cout << "Get child 6: "  << BUI->getChild(6)->getType() << ": " << BUI->getChild(6)->getPrice() << " money " << "Taken: " << BUI->getChild(6)->getTaken() << endl;
    cout << "Get child 7: "  << BUI->getChild(7)->getType() << ": " << BUI->getChild(7)->getPrice() << " money " << "Taken: " << BUI->getChild(7)->getTaken() << endl;
    cout << "Get child 8: "  << BUI->getChild(8)->getType() << ": " << BUI->getChild(8)->getPrice() << " money " << "Taken: " << BUI->getChild(8)->getTaken() << endl;
    cout << "Get child 9: "  << BUI->getChild(9)->getType() << ": " << BUI->getChild(9)->getPrice() << " money " << "Taken: " << BUI->getChild(9)->getTaken() << endl;
    cout << "Get child 10: "  << BUI->getChild(10)->getType() << ": " << BUI->getChild(10)->getPrice() << " money " << "Taken: " << BUI->getChild(10)->getTaken() << endl;

    //Initialize Citizen
    cout << endl << "---------Initialize Citizen---------" << endl;
    CitizenFactory* CITF = new ConcreteCitizenFactory(BUI, globalGovern);
    ConcreteCitizen* CC1 = CITF->createCitizen();
    ConcreteCitizen* CC2 = CITF->createCitizen();

    //Give citizen houses and employments
    cout << endl << endl << "---------Give citizen's houses and employments---------" << endl;
    CC1->getHouse();
    CC1->getHouse();
    CC1->getHouse();
    CC1->getEmployment();
    CC1->getHouse();
    cout << endl;
    CC2->getEmployment();
    CC2->getHouse();

    cout << endl << "---------Clone Citizen 1---------" << endl;
    ConcreteCitizen* CC3 = CC1->clone();

    //Print Tree of Buildings
    cout << endl << endl << "---------Print Current Tree of Buildings---------" << endl;
    cout << "Get child 0: "  << BUI->getChild(0)->getType() << ": " << BUI->getChild(0)->getPrice() << " money " << "Taken: " << BUI->getChild(0)->getTaken() << endl;
    cout << "Get child 1: "  << BUI->getChild(1)->getType() << ": " << BUI->getChild(1)->getPrice() << " money " << "Taken: " << BUI->getChild(1)->getTaken() << endl;
    cout << "Get child 2: "  << BUI->getChild(2)->getType() << ": " << BUI->getChild(2)->getPrice() << " money " << "Taken: " << BUI->getChild(2)->getTaken() << endl;
    cout << "Get child 3: "  << BUI->getChild(3)->getType() << ": " << BUI->getChild(3)->getPrice() << " money " << "Taken: " << BUI->getChild(3)->getTaken() << endl;
    cout << "Get child 4: "  << BUI->getChild(4)->getType() << ": " << BUI->getChild(4)->getPrice() << " money " << "Taken: " << BUI->getChild(4)->getTaken() << endl;
    cout << "Get child 5: "  << BUI->getChild(5)->getType() << ": " << BUI->getChild(5)->getPrice() << " money " << "Taken: " << BUI->getChild(5)->getTaken() << endl;
    cout << "Get child 6: "  << BUI->getChild(6)->getType() << ": " << BUI->getChild(6)->getPrice() << " money " << "Taken: " << BUI->getChild(6)->getTaken() << endl;
    cout << "Get child 7: "  << BUI->getChild(7)->getType() << ": " << BUI->getChild(7)->getPrice() << " money " << "Taken: " << BUI->getChild(7)->getTaken() << endl;
    cout << "Get child 8: "  << BUI->getChild(8)->getType() << ": " << BUI->getChild(8)->getPrice() << " money " << "Taken: " << BUI->getChild(8)->getTaken() << endl;
    cout << "Get child 9: "  << BUI->getChild(9)->getType() << ": " << BUI->getChild(9)->getPrice() << " money " << "Taken: " << BUI->getChild(9)->getTaken() << endl;
    cout << "Get child 10: "  << BUI->getChild(10)->getType() << ": " << BUI->getChild(10)->getPrice() << " money " << "Taken: " << BUI->getChild(10)->getTaken() << endl;


    cout << endl << "---------Collect Taxes---------" << endl;
    cout << "Current City Bank Amount: " << globalGovern->get() << " money" << endl;
    cout << "Collecting Tax's according to: IncomeTaxStrategy" << endl;
    int taxAmount = globalGovern->collectTax();
    cout << "Taxes amount per person: " << taxAmount << " money" << endl;
    cout << endl << "Before Taxes: " << endl;
    cout << "CC1: " << CC1->bank->get() << " money" << endl;
    cout << "CC2: " << CC2->bank->get() << " money" << endl;
    cout << "CC3: " << CC3->bank->get() << " money" << endl;
    CC1->getTax(taxAmount);
    CC2->getTax(taxAmount);
    cout << endl << "After Taxes: " << endl;
    cout << "CC1: " << CC1->bank->get() << " money" << endl;
    cout << "CC2: " << CC2->bank->get() << " money" << endl;
    cout << "CC3: " << CC3->bank->get() << " money" << endl;
    cout << endl << "New City Bank Amount: " << globalGovern->get() << " money" << endl;

    cout << endl << "---------Citizen Using all transportation forms---------" << endl;
    cout << "CC2: " << CC2->bank->get() << " money\nTaxis" << endl;
    CC2->useTransport("Taxis");
    cout << endl;
    cout << "CC2: " << CC2->bank->get() << " money\nBuses" << endl;
    CC2->useTransport("Buses");
    cout << endl;
    cout << "CC2: " << CC2->bank->get() << " money\nAirport" << endl;
    CC2->useTransport("Airport");
    cout << endl;
    cout << "CC2: " << CC2->bank->get() << " money\nTrain" << endl;
    CC2->useTransport("Train");
    cout << endl << "Total Money left for CC2: " << CC2->bank->get() << " money" << endl;

    cout << endl << "---------Situations getting causes---------" << endl;
    for(int i  = 0; i < 23; i++)
    {
        globalGovern->randomEvent();
    }
    

    return 0;
}