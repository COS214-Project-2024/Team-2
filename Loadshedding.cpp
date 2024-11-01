#include "Loadshedding.h"
#include <iostream>
#include "Government.h"
using namespace std;

bool Loadshedding::execute()
{
    string response;
    cout << "Loadshedding has occured in the city." << endl;
    cout << "Electricity has been reduced.\n Resolve issue by typing Y: " << endl;
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