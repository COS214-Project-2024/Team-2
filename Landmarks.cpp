#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Landmarks.h"

using namespace std;

Landmarks::Landmarks(string t)
{
    for(int i = 0; i < 3; i++)
    {
        if(type[i] == t)
        {
            position = i;
        }
    }
}

string Landmarks::getType()
{
    return myType;
}

int Landmarks::getPrice()
{
    return price[position];
}

int Landmarks::getPosition()
{
    return position;
}

int Landmarks::getSatisfaction()
{
    return satisfactionRate;
}

void Landmarks::setPrice(int pric)
{
    price[position] = pric;
}

bool Landmarks::getTaken()
{
    return taken;
}

void Landmarks::setTaken(bool tak)
{
    taken = tak;
}