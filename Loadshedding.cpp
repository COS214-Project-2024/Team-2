#include "Loadshedding.h"
#include <iostream>
#include "Government.h"

using namespace std;

/**
 * @brief Executes the load shedding command.
 * 
 * This method simulates the occurrence of load shedding in the city by
 * displaying a message to the user and prompting for a response. Based on
 * a random value, it determines whether the load shedding has been stopped
 * and returns the appropriate result.
 * 
 * @return true if load shedding has been stopped, false otherwise.
 */
bool Loadshedding::execute()
{
    string response;
    cout << endl << endl << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\nLoadshedding has occurred in the city." << endl;
    cout << "Electricity has been reduced.\nResolve issue by typing Y: ";
    cin >> response;

    // Generate a random value to determine the outcome of the load shedding
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
