#ifndef Landmarks_h
#define Landmarks_h

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Buildings.h"

using namespace std;

class Landmarks : public Buildings
{
    private:
        string type[3] = {"parks", "monuments", "culturecenters"};
        int price[3] = {300, 500, 350};
        int position;
        int satisfactionRate = 2;
        string myType = "landmarks";
        bool taken = false;

    public:
        Landmarks(string type);
        std::string getType();
        int getPrice();
        int getPosition();
        int getSatisfaction();
        void setPrice(int p);
        bool getTaken();
        void setTaken(bool t);
};

#endif