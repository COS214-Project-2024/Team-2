#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Commercial.h"

using namespace std;

Commercial::Commercial(string t)
{
    for(int i = 0; i < 3; i++)
    {
        if(type[i] == t)
        {
            position = i;
        }
    }
}

string Commercial::getType()
{
    return myType;
}

int Commercial::getPrice()
{
    return price[position];
}

int Commercial::getPosition()
{
    return position;
}

int Commercial::getSatisfaction()
{
    return satisfactionRate;
}

void Commercial::setPrice(int pric)
{
    price[position] = pric;
}

bool Commercial::getTaken()
{
    return taken;
}

void Commercial::setTaken(bool tak)
{
    taken = tak;
}