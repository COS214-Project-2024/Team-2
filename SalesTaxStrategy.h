#ifndef SALESTAXSTRATEGY_H
#define SALESTAXSTRATEGY_H

#include "TaxStrategy.h"

/**
 * @brief Concrete implementation of TaxStrategy for calculating sales tax.
 * 
 * This class implements the calculateTax method to apply a sales tax rate
 * of 15% to the total amount.
 */
class SalesTaxStrategy : public TaxStrategy
{
    public:
        /**
         * @brief Calculates the sales tax for a given total amount.
         * 
         * @param total The total amount on which to calculate the sales tax.
         * @return The calculated sales tax amount.
         */
        int calculateTax(int total) override
        {
            return (total * 0.15);            
        };
};

#endif
