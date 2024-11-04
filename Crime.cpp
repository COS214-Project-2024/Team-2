#include "Crime.h"
#include <iostream>
#include "Government.h"
using namespace std;

bool Crime::execute()
{
    string response;
    cout << endl << endl << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\nCrime has occured in the city.\nOn which superhero will you call, if any? (Batman, Superman, Spiderman or None)";
    cin >> response;
    int randomValue = std::rand() % 2;
    if (response == "Batman")
    {
        if(randomValue == 1)
        {
            cout << "Batman pays crime stoppers to do the job for him." << endl;
            return true;
        }
        else
        {
            cout << "Superhero got lost on his way here,\n Crime will continue to run rampant" << endl;
            return false;
        }
    }
    else if (response == "Superman")
    {
        if(randomValue == 1)
        {
            cout << "Superman stops the crime with ease" << endl;
            return true;
        }
        else
        {
            cout << "Superhero got lost on his way here,\n Crime will continue to run rampant" << endl;
            return false;
        }
    }
    else if (response == "Spiderman")
    {
        if(randomValue == 1)
        {
            cout << "Spiderman just swings I geuss..." << endl;
            return true;
        }
        else
        {
            cout << "Superhero got lost on his way here,\n Crime will continue to run rampant" << endl;
            return false;
        }
    }
    else 
    {
        cout << "No superhero has been called.\n Crime will continue to run rampant" << endl;
    }
    return false;
}