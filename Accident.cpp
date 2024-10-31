#include "Accident.h"
#include <iostream>
#include "Government.h"
using namespace std;

void Accident::execute(){
    string response;
    cout << "An accident has occured in the city.\n
    Transportation has been halted for the time being.\n
    Do you want to resolve it? (Y or N)" << endl;
    Government::setTransport(false);
    cin >> response;
    
    if (response == "Y")
    {
        cout << "The accident has been resolved and transportation has been resumed" << endl;
        Government::setTransport(true);
    }
    else
    {
        cout << "The accident has not been resolved." << endl;
    }
    
}