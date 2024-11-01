#include <iostream>
using namespace std;

#include "Buses.h"
#include "Bank.h"

void Buses::move(Bank bank)
{
    if(Bank::bank->get() > this->price){
        cout << "Citizen used bus transportation." << endl;
        cout << "They are traveling at a maximum speed of " << this->speedOfVehicle << endl;
        Bank::decrement(this->price);
    }else{
        cout << "Citizen did not use bus transportation, they are too poor." << endl;
    }
}