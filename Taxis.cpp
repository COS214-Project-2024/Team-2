#include <iostream>
using namespace std;

#include "Taxis.h"
#include "Bank.h"

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