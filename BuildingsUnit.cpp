#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "BuildingsUnit.h"

using namespace std;

/**
 * @brief Constructs a BuildingsUnit with a specified Government authority.
 * 
 * @param gover Pointer to the Government instance managing this BuildingsUnit.
 */
BuildingsUnit::BuildingsUnit(Government* gover)
{
    govern = gover;
}

/**
 * @brief Adds a building component to the unit if funds are sufficient.
 * 
 * @param childrenp Pointer to the Buildings object to add.
 */
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

/**
 * @brief Removes a building component at a specified index.
 * 
 * @param i Index of the building component to remove from the unit.
 */
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

/**
 * @brief Retrieves a child building component at a specified index.
 * 
 * @param i Index of the building component to retrieve.
 * @return Pointer to the Buildings object at the specified index, or NULL if out of bounds.
 */
Buildings* BuildingsUnit::getChild(int i) 
{
    if (i >= 0 && i < static_cast<int>(children.size())) 
    {
        return children[i];
    }
    return NULL;
}

/**
 * @brief Deletes all buildings of a specific type within the unit.
 * 
 * @param mT The type of buildings to delete.
 */
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

/**
 * @brief Calculates and outputs the total price of all buildings of a specific type.
 * 
 * @param mT The type of buildings to calculate the total price for.
 */
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

/**
 * @brief Sets a new price for all buildings of a specific type.
 * 
 * @param mT The type of buildings to update the price for.
 * @param p The new price to set for each building of this type.
 */
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

/**
 * @brief Attempts to find an available house within the unit.
 * 
 * @return True if a house was found and marked as occupied, otherwise false.
 */
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

/**
 * @brief Attempts to find available employment within the unit.
 * 
 * @return True if employment was found and marked as occupied, otherwise false.
 */
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

/**
 * @brief Requests utilities required for the unit, including materials, water, and power.
 */
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

/**
 * @brief Destructor for BuildingsUnit, deallocates all child building components.
 */
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