#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Industrial.h"

using namespace std;

Industrial::Industrial(string t)
{
    for(int i = 0; i < 3; i++)
    {
        if(type[i] == t)
        {
            position = i;
        }
    }
}

string Industrial::getType()
{
    return myType;
}

int Industrial::getPrice()
{
    return price[position];
}

int Industrial::getPosition()
{
    return position;
}

int Industrial::getSatisfaction()
{
    return satisfactionRate;
}

void Industrial::setPrice(int pric)
{
    price[position] = pric;
}

bool Industrial::getTaken()
{
    return taken;
}

void Industrial::setTaken(bool tak)
{
    taken = tak;
}