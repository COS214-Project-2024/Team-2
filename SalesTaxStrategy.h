#ifndef SALESTAXSTRATEGY_H
#define SALESTAXSTRATEGY_H

#include "TaxStrategy.h"

class SalesTaxStrategy : public TaxStrategy
{
    public:
        int calculateTax(int total) override
        {
            return total * (15/100);            
        };
};

#endif