#include <iostream>
using namespace std;
#include "Department.h"

Department::Department() 
{
    this->citizenSatisfactionRate = 2;
}

int Department::getSatisfaction() 
{
    return this->citizenSatisfactionRate;
}

void Department::setSatisfaction(int level, Bank* bank) 
{
    if(level > -1 && level < 11)
    {
        this->citizenSatisfactionRate = level;
    }
    if(this->citizenSatisfactionRate == 0)
    {
        int randomValue = std::rand() % 2;
        string temp;
        cout << "Your citizen satisfaction rate is 0!" << endl;
        cout << 3 << " Houses got broken down during a riot!\nHeres a tip! ;p  use the cheatCode \"weewooweewoo\": ";
        cin >> temp;
        if(temp == "weewooweewoo")
        {
            bank->increment(20000);
            cout << "You just got 20000 money...\nits a pleasure doing business with you >:)" << endl;
        }
        else
        {
            cout << "Missed typed! Sorry Missed your chance!" << endl;
        }
    }
    else if(this->citizenSatisfactionRate == 2)
    {
        cout << "Your citizen satisfaction rate is 2!" << endl;
        cout << "You Recieved a bonus of: 100 money!" << endl;
        bank->increment(100);
    }
    else if(this->citizenSatisfactionRate == 4)
    {
        cout << "Your citizen satisfaction rate is 4!" << endl;
        cout << "You Recieved a bonus of: 200 money!" << endl;
        bank->increment(200);
    }
    else if(this->citizenSatisfactionRate == 6)
    {
        cout << "Your citizen satisfaction rate is 6!" << endl;
        cout << "You Recieved a bonus of: 300 money!" << endl;
        bank->increment(300);
    }
    else if(this->citizenSatisfactionRate == 8)
    {
        cout << "Your citizen satisfaction rate is 8!" << endl;
        cout << "You Recieved a bonus of: 400 money!" << endl;
        bank->increment(400);
    }
    else if(this->citizenSatisfactionRate == 10)
    {
        cout << "Your citizen satisfaction rate is 10!\nYou've reached the maximum number if satisfaction!" << endl;
        cout << "You beated the game!\nYou Recieved a bonus of: 1000 money!\nYou can continue playing if you like!" << endl;
        bank->increment(1000);
    }
}