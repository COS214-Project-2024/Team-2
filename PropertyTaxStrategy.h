#ifndef PROPERTYTAXSTRATEGY_H
#define PROPERTYTAXSTRATEGY_H

#include "TaxStrategy.h"

class PropertyTaxStrategy : public TaxStrategy
{
    public:
        double calculateTax(int total) override
        {
            return total * (2/100);            
        };
};

#endif