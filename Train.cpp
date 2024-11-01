#include <iostream>
using namespace std;

#include "Train.h"
#include "Bank.h"

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