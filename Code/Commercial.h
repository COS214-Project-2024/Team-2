#ifndef Commercial_h
#define Commercial_h

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Buildings.h"

using namespace std;

class Commercial : public Buildings
{
    private:
        string type[3] = {"shops", "offices", "malls"};
        int price[3] = {350, 100, 450};
        int position;
        int satisfactionRate = 1;
        string myType = "commercial";
        bool taken = false;

    public:
        Commercial(string type);
        std::string getType();
        int getPrice();
        int getPosition();
        int getSatisfaction();
        void setPrice(int p);
        bool getTaken();
        void setTaken(bool t);
};

#endif