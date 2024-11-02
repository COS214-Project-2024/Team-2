#ifndef PROPERTYTAXSTRATEGY_H
#define PROPERTYTAXSTRATEGY_H

#include "TaxStrategy.h"

class PropertyTaxStrategy : public TaxStrategy
{
    public:
        int calculateTax(int total)
        {
            return (total * 0.2);            
        };
};

#endif