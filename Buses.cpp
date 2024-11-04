#include <iostream>
using namespace std;

#include "Buses.h"
#include "Bank.h"

/**
 * @brief Executes the bus movement logic.
 * 
 * This method checks the user's bank balance and determines whether they can 
 * afford to use the bus. It updates the balance accordingly and provides feedback 
 * to the user about the transaction.
 * 
 * @param bank Pointer to the Bank object that manages the user's balance.
 */
void Buses::move(Bank* bank)
{
    if(bank->get() > this->price){
        cout << "Citizen used bus transportation." << endl;
        cout << "They are traveling at a maximum speed of " << this->speedOfVehicle << endl;
        bank->decrement(this->price);
    }else{
        cout << "Citizen did not use bus transportation, they are too poor." << endl;
    }
}