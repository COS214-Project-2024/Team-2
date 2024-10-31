#include "Loadshedding.h"
#include <iostream>
#include "Government.h"
using namespace std;

void Loadshedding::execute(){
    string response;
    cout << "Loadshedding has occured in the city. Tax has been collected." << endl;
    Government::collectTax();
    Government::setTransport(false);
    cout << "Electricity has been reduced.\n
    Do you want to stop loadshedding? (Y or N)" << endl;
    useResource("energy");
    cin >> response;
    if (response == "Y")
    {
        cout << "Loadshedding has been stopped and transportation has been resumed" << endl;
        Government::setTransport(true);
    }
    else
    {
        cout << "Loadshedding has not been stopped." << endl;
    }
}