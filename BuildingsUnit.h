#ifndef BuildingsUnit_h
#define BuildingsUnit_h

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Buildings.h"
#include "Utilities.h"
#include "Government.h"

using namespace std;

class BuildingsUnit : public Buildings
{
    private:
        std::vector<Buildings*> children;
        Government* govern;
        Utilities* utilities;
    public:
        BuildingsUnit(Government* g);
        void add(Buildings* comp);
        void remove(int index);
        Buildings* getChild(int index);
        void deleteSpecificTree(string myType);
        void getTreePrice(string myType);
        void setTreePrice(string myType, int price);
        bool getHouse();
        bool getEmployment();
        void requestUtilities();
        ~BuildingsUnit();
};

#endif