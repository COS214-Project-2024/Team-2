#ifndef Buildings_H
#define Buildings_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;

class Buildings
{
    public:
        virtual void add(Buildings* component);
        virtual void remove(Buildings* component);
        virtual string getType();
        virtual int getPrice();
        virtual void setPrice(int p);
        virtual bool getTaken();
        virtual void setTaken(bool t);
};

#endif