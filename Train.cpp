#include <iostream>
using namespace std;

#include "Train.h"
#include "Bank.h"

/**
 * @brief Moves a citizen using the train if they can afford the fare.
 * 
 * This method checks the bank balance of the citizen. If the balance is
 * greater than the fare for the train, the citizen will use the train
 * for transportation. The method also prints the speed of the train and
 * decrements the bank balance by the train fare. If the balance is not
 * sufficient, a message indicating that the citizen cannot afford the
 * transportation is displayed.
 * 
 * @param bank A pointer to the Bank object that contains the citizen's bank balance.
 */
void Train::move(Bank* bank)
{
    if(bank->get() > this->price){
        cout << "Citizen used train transportation." << endl;
        cout << "They are traveling at a maximum speed of " << this->speedOfVehicle << endl;
        bank->decrement(this->price);
    }else{
        cout << "Citizen did not use train transportation, they are too poor." << endl;
    }
}