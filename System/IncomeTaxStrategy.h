#ifndef INCOMETAXSTRATEGY_H
#define INCOMETAXSTRATEGY_H

#include "TaxStrategy.h"

/**
 * @brief Implements a strategy for calculating income tax.
 * 
 * This class provides a specific implementation of the TaxStrategy 
 * for calculating tax based on a fixed percentage of the total income.
 */
class IncomeTaxStrategy : public TaxStrategy
{
    public:
        /**
         * @brief Calculates the income tax based on the total income.
         * 
         * This method applies a tax rate of 10% to the given total income.
         * 
         * @param total The total income on which the tax is to be calculated.
         * @return The calculated income tax amount.
         */
        int calculateTax(int total)
        {
            return (total * 0.1);            
        };
};

#endif
