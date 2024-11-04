#include "BuildingIterator.h"

BuildingIterator::BuildingIterator(Buildings* root) 
{
    if(root != nullptr) 
    {
        stack.push(root);
    }
    current = nullptr;
}

Buildings* BuildingIterator::firstNode() 
{
    if(!stack.empty()) 
    {
        current = stack.top();
    }
    return current;
}

void BuildingIterator::next(std::vector<Buildings*> children) 
{
    if (!stack.empty()) 
    {
        Buildings* node = stack.top();
        stack.pop();

        for (auto it = children.rbegin(); it != children.rend(); ++it) 
        {
            stack.push(*it);
        }

        current = stack.empty() ? nullptr : stack.top();
    }
}

bool BuildingIterator::isDone() const {
    return stack.empty();
}

Buildings* BuildingIterator::currentNode() const {
    return current;
}
