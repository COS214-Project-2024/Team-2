#include "Crime.h"
#include <iostream>
#include "Government.h"
using namespace std;

void Crime::execute(){
    string response;
    cout << "Crime has occured in the city.\n
    On which superhero will you call, if any? (Batman, Superman, Spiderman or None)" << endl;
    cout << "Taxes have been collected due to crimes." << endl;
    collectTax();
    Government::setTransport(false);
    cin >> response;
    
    if (response == "Batman"){
        cout << "Batman pays crime stoppers to do the job for him." << endl;
    }else if (response == "Superman"){
        cout << "Superman stops the crime with ease" << endl;
    }else if (response == "Spiderman"){
        cout << "" << endl;
    }else {
        cout << "No superhero has been called.\n
        Crime will continue to run rampant" << endl;
        cout << "Transportation has been halted for the time being." << endl;
    }
    
}