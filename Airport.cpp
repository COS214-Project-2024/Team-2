#include <iostream>
using namespace std;

#include "Airport.h"
#include "Bank.h"

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