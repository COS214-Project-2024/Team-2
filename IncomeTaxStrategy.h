#ifndef INCOMETAXSTRATEGY_H
#define INCOMETAXSTRATEGY_H

#include "TaxStrategy.h"

class IncomeTaxStrategy : public TaxStrategy
{
    public:
        int calculateTax(int total)
        {
            return (total * 0.1);            
        };
};

#endif