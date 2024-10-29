#ifndef INCOMETAXSTRATEGY_H
#define INCOMETAXSTRATEGY_H

#include "TaxStrategy.h"

class IncomeTaxStrategy : public TaxStrategy
{
    public:
        int calculateTax(int total) override
        {
            return total * (10/100);            
        };
};

#endif