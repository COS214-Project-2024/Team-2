#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Residential.h"

using namespace std;

Residential::Residential(string t)
{
    for(int i = 0; i < 3; i++)
    {
        if(type[i] == t)
        {
            position = i;
        }
    }
}

string Residential::getType()
{
    return myType;
}

int Residential::getPrice()
{
    return price[position];
}

int Residential::getPosition()
{
    return position;
}

int Residential::getSatisfaction()
{
    return satisfactionRate;
}

void Residential::setPrice(int pric)
{
    price[position] = pric;
}

bool Residential::getTaken()
{
    return taken;
}

void Residential::setTaken(bool tak)
{
    taken = tak;
}