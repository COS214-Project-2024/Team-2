#include "Accident.h"
#include <iostream>
#include "Government.h"
using namespace std;

/**
 * @brief Executes the response command for an accident situation.
 *
 * This method simulates an accident event occurring in the city and prompts the user
 * for a response. A random value determines the outcome of the event, indicating
 * whether the accident was successfully resolved or not.
 * 
 * @return True if the accident is resolved successfully, otherwise false.
 */
bool Accident::execute()
{
    string response;
    cout << endl << endl << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\nAn accident has occured in the city.\nResolve issue by typing Y: ";
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