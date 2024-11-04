#ifndef BUILDINGITERATOR_H
#define BUILDINGITERATOR_H

#include <stack>
#include "Buildings.h"

class BuildingIterator 
{
public:
    BuildingIterator(Buildings* root);

    Buildings* firstNode();
    void next(std::vector<Buildings*> children);
    bool isDone() const;
    Buildings* currentNode() const;

private:
    std::stack<Buildings*> stack;
    Buildings* current;
};

#endif
