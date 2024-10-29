#ifndef Industrial_h
#define Industrial_h

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Buildings.h"

using namespace std;

class Industrial : public Buildings
{
    private:
        string type[3] = {"factories", "warehouses", "plants"};
        int price[3] = {500, 450, 400};
        int position;
        int satisfactionRate = 2;
        string myType = "industrial";
        bool taken = false;

    public:
        Industrial(string type);
        std::string getType();
        int getPrice();
        int getPosition();
        int getSatisfaction();
        void setPrice(int p);
        bool getTaken();
        void setTaken(bool t);
};

#endif