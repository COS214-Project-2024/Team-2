#include <iostream>
using namespace std;
#include "Department.h"

/**
 * @brief Constructs a Department object.
 * 
 * Initializes the citizen satisfaction rate to a default value.
 */
Department::Department() 
{
    this->citizenSatisfactionRate = 2; // Default satisfaction rate
}

/**
 * @brief Retrieves the current citizen satisfaction rate.
 * 
 * @return The current satisfaction rate of citizens.
 */
int Department::getSatisfaction() 
{
    return this->citizenSatisfactionRate; // Return current satisfaction rate
}

/**
 * @brief Sets the citizen satisfaction rate and provides feedback.
 * 
 * Updates the citizen satisfaction rate based on the input level and 
 * provides bonuses or penalties based on the new rate.
 * 
 * @param level The new satisfaction level to set (must be between 0 and 10).
 * @param bank Pointer to a Bank object used for monetary transactions.
 */
void Department::setSatisfaction(int level, Bank* bank) 
{
    // Ensure the level is within the valid range
    if(level > -1 && level < 11)
    {
        this->citizenSatisfactionRate = level; // Update satisfaction rate
    }
    
    // Provide feedback based on the current satisfaction rate
    if(this->citizenSatisfactionRate == 0)
    {
        int randomValue = std::rand() % 2;
        string temp;
        cout << "Your citizen satisfaction rate is 0!" << endl;
        cout << 3 << " Houses got broken down during a riot!\nHeres a tip! ;p  use the cheatCode \"weewooweewoo\": ";
        cin >> temp;
        if(temp == "weewooweewoo")
        {
            bank->increment(20000); // Grant bonus for cheat code
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
        bank->increment(100); // Grant bonus for satisfaction level 2
    }
    else if(this->citizenSatisfactionRate == 4)
    {
        cout << "Your citizen satisfaction rate is 4!" << endl;
        cout << "You Recieved a bonus of: 200 money!" << endl;
        bank->increment(200); // Grant bonus for satisfaction level 4
    }
    else if(this->citizenSatisfactionRate == 6)
    {
        cout << "Your citizen satisfaction rate is 6!" << endl;
        cout << "You Recieved a bonus of: 300 money!" << endl;
        bank->increment(300); // Grant bonus for satisfaction level 6
    }
    else if(this->citizenSatisfactionRate == 8)
    {
        cout << "Your citizen satisfaction rate is 8!" << endl;
        cout << "You Recieved a bonus of: 400 money!" << endl;
        bank->increment(400); // Grant bonus for satisfaction level 8
    }
    else if(this->citizenSatisfactionRate == 10)
    {
        cout << "Your citizen satisfaction rate is 10!\nYou've reached the maximum number if satisfaction!" << endl;
        cout << "You beated the game!\nYou Recieved a bonus of: 1000 money!\nYou can continue playing if you like!" << endl;
        bank->increment(1000); // Grant bonus for maximum satisfaction
    }
}
