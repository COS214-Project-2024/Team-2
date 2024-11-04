#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "BuildingsUnit.h"

using namespace std;

BuildingsUnit::BuildingsUnit(Government* gover)
{
    govern = gover;
}

void BuildingsUnit::add(Buildings* childrenp) 
{
    if(govern->get() >= childrenp->getPrice())
    {
        govern->decrement(childrenp->getPrice());
        requestUtilities();
        govern->cityGrow(childrenp->getType());
        children.push_back(childrenp);
        cout << endl << "Succesfully build building: " << childrenp->getType() << endl;
        cout << "It costed: " << childrenp->getPrice() << " money           Your bank: " << govern->get() << " money" << endl << endl;
    }
    else
    {
        cout << "Unsuccesfully build building " << childrenp->getType() << endl;
        cout << "It costed: " << childrenp->getPrice() << " money           Your bank: " << govern->get() << " money" << endl << endl;
    }
}

void BuildingsUnit::remove(int i) 
{
    if(i >= 0 && i < static_cast<int>(children.size()) && children[i] != NULL)
    {
        std::vector<Buildings*>::iterator it;
        for(it = children.begin(); it != children.end(); ++it) 
        {
            if(*it == children[i]) 
            {
                govern->cityShrink(children[i]->getType());
                cout << "Succesfully removed building: " << children[i]->getType() << endl << endl;
                children.erase(it);
                break;
            }
        }
    }
}

Buildings* BuildingsUnit::getChild(int i) 
{
    if (i >= 0 && i < static_cast<int>(children.size())) 
    {
        return children[i];
    }
    return NULL;
}

void BuildingsUnit::deleteSpecificTree(string mT)
{
    std::vector<Buildings*>::iterator it;
    int count = 0;
    for(it = children.begin(); it != children.end(); ++it) 
    {
        if(children[count]->getType() == mT) 
        {
            remove(count);
        }
        ++count;
    }
    cout << "Tree " << mT << " got deleted " << endl;
}

void BuildingsUnit::getTreePrice(string mT)
{
    std::vector<Buildings*>::iterator it;
    int temp = 0;

    for (it = children.begin(); it != children.end(); ++it) 
    {
        if ((*it)->getType() == mT) 
        {
            temp += (*it)->getPrice();
        }
    }

    std::cout << "Current Tree Price of " << mT << ": " << temp << " money" << std::endl;
}

void BuildingsUnit::setTreePrice(string mT, int p)
{
    std::vector<Buildings*>::iterator it;
    int temp = 0;

    for (it = children.begin(); it != children.end(); ++it) 
    {
        if ((*it)->getType() == mT) 
        {
            (*it)->setPrice(p);
        }
    }
    getTreePrice(mT);
}

bool BuildingsUnit::getHouse()
{
    std::vector<Buildings*>::iterator it;
    int count = 0;
    for(it = children.begin(); it != children.end(); ++it) 
    {
        if(children[count]->getType() == "residential" || children[count]->getType() == "commercial") 
        {
            if(!(children[count]->getTaken())) 
            {
                children[count]->setTaken(true);
                return true;
            }
        }
        ++count;
    }

    return false;
}

bool BuildingsUnit::getEmployment()
{
    std::vector<Buildings*>::iterator it;
    int count = 0;
    for(it = children.begin(); it != children.end(); ++it) 
    {
        if(children[count]->getType() == "industrial" || children[count]->getType() == "landmarks") 
        {
            if(!(children[count]->getTaken())) 
            {
                children[count]->setTaken(true);
                return true;
            }
        }
        ++count;
    }

    return false;
}

void BuildingsUnit::requestUtilities() 
{
    Utilities* materialFactory = new MaterialFactory();
    Utilities* waterSupply = new WaterSupply();
    Utilities* powerPlant = new PowerPlant();

    materialFactory->setNext(waterSupply);
    waterSupply->setNext(powerPlant);

    materialFactory->handleRequest(govern);

    delete materialFactory;
    delete waterSupply;
    delete powerPlant;
}

BuildingsUnit::~BuildingsUnit() 
{
    for(int i = 0; i < static_cast<int>(children.size()); i++)
    {
        if(children[i] != NULL)
        {
            delete children[i];
        }
    }
    if(!(children.empty()))
    {
        children.clear();
    }
}