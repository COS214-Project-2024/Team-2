#include "Accident.h"
#include <iostream>
#include "Government.h"
using namespace std;

bool Accident::execute()
{
    string response;
    cout << "An accident has occured in the city.\n Resolve issue by typing Y: " << endl;
    cin >> response;
    int randomValue = std::rand() % 2;
    if (randomValue == 1)
    {
        cout << "The accident has been resolved and transportation has been resumed" << endl;
        return true;
    }
    else
    {
        cout << "The accident has not been resolved." << endl;
        return false;
    }
    return false;
}