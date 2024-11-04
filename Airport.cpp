#include <iostream>
using namespace std;

#include "Airport.h"
#include "Bank.h"

/**
 * @brief Moves a citizen using airport transportation.
 * 
 * This method verifies if the citizen has enough funds to cover the transportation cost.
 * If they do, a message is printed, and the citizen's funds are decremented by the
 * required amount. If not, a message indicates insufficient funds.
 * 
 * @param bank A pointer to the Bank instance representing the citizen's funds.
 */
void Airport::move(Bank* bank)
{
    if(bank->get() > this->price){
        cout << "Citizen used airport transportation." << endl;
        cout << "They are traveling at a maximum speed of " << this->speedOfVehicle << endl;
        bank->decrement(this->price);
    }else{
        cout << "Citizen did not use airport transportation, they are too poor." << endl;
    }
}