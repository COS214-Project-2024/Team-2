#ifndef Residential_h
#define Residential_h

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Buildings.h"

using namespace std;

class Residential : public Buildings
{
    private:
        string type[3] = {"houses", "apartments", "estates"};
        int price[3] = {200, 100, 250};
        int position;
        int satisfactionRate = 1;
        string myType = "residential";
        bool taken = false;

    public:
        Residential(string type);
        std::string getType();
        int getPrice();
        int getPosition();
        int getSatisfaction();
        void setPrice(int p);
        bool getTaken();
        void setTaken(bool t);
};

#endif