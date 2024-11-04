#include <iostream>
using namespace std;

#include "Taxis.h"
#include "Bank.h"

/**
 * @brief Moves the taxi to the specified bank if the citizen can afford the fare.
 * 
 * This method checks if the citizen has enough funds in their bank account 
 * to pay for the taxi fare. If they do, it simulates the use of the taxi 
 * service by decrementing the bank balance and outputting travel information. 
 * If not, it indicates that the citizen cannot afford the taxi service.
 * 
 * @param bank Pointer to the Bank object representing the citizen's bank account.
 */
void Taxis::move(Bank* bank)
{
    if(bank->get() > this->price){
        cout << "Citizen used taxis transportation." << endl;
        cout << "They are traveling at a maximum speed of " << this->speedOfVehicle << endl;
        bank->decrement(this->price);
    }else{
        cout << "Citizen did not use taxis transportation, they are too poor." << endl;
    }
}