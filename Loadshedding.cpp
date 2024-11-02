#include "Loadshedding.h"
#include <iostream>
#include "Government.h"
using namespace std;

bool Loadshedding::execute()
{
    string response;
    cout << endl << endl << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\nLoadshedding has occured in the city." << endl;
    cout << "Electricity has been reduced.\nResolve issue by typing Y: ";
    cin >> response;
    int randomValue = std::rand() % 2;
    if (randomValue == 1)
    {
        cout << "Loadshedding has been stopped and transportation has been resumed" << endl;
        return true;
    }
    else
    {
        cout << "Loadshedding has not been stopped." << endl;
        return false;
    }
}