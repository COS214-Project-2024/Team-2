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

/** 
 * @mainpage
 * 
 * # Project Documentation
 * 
 * City Builder Simulation
 * Welcome to our COS 214 City Builder Simulation project! Built as a 2nd year group project, this C++ simulation allows players to engage with various aspects of a virtual city, integrating key urban components like infrastructure, citizen satisfaction, resource management, and more.<br/>
 * Designed with flexibility and scalability, this simulation employs numerous design patterns to achieve a complex, dynamic urban environment.
 * 
 * 👥 The Team: IDK<br/>
 * Student Number   Name<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;u23587832&   Hannah Koorbanally<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;u23673941&   Louise Bruwer<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;u23530996&   Kiara Hodgson<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;u23605376&   Brendan du Plooy<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;u21439631&   Euan Botha<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;u21437883&   Nolan Kühn<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;u23782219&   Ruan le Roux<br/><br/>
 * 
 * 🧠 Design Patterns<br/>
 * This project utilises various software design patterns to manage different components of the city. These include, but are not limited to:
 * 
 * &nbsp;&nbsp;&nbsp;&nbsp;State<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;Strategy<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;Mediator<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;Composite<br/><br/>
 * 
 * UML Diagrams and more details on patterns can be found in the project documentation (Structures, Report etc...)<br/><br/>
 * 
 * 💻 Guide to running:<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;make clean<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;make<br/>
 * 
 * Demo:<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;./main<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;Y<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;Batman<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;Batman<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;Y<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;None<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;None<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;None<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;Batman<br/>
 * &nbsp;&nbsp;&nbsp;&nbsp;weewooweewoo<br/>
 */


/**
 * @brief The main entry point for the city simulation application.
 *
 * This program initializes a government and a collection of buildings,
 * adds them to a building unit, creates citizens, assigns properties and 
 * jobs to them, and processes taxes. It also simulates various situations 
 * affecting the city.
 *
 * @return int Exit status of the program.
 */
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
    cout << endl << "Total Money left for CC2: " << CC2->bank2->get() << " money" << endl;

    cout << endl << "---------Situations getting causes---------" << endl;
    for(int i  = 0; i < 23; i++)
    {
        globalGovern->randomEvent();
    }
    

    return 0;
}