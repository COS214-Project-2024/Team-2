#ifndef PROPERTYTAXSTRATEGY_H
#define PROPERTYTAXSTRATEGY_H

#include "TaxStrategy.h"

/**
 * @brief Strategy for calculating property tax.
 * 
 * The PropertyTaxStrategy class inherits from the TaxStrategy class and
 * provides an implementation for calculating property taxes based on the
 * total value provided.
 */
class PropertyTaxStrategy : public TaxStrategy
{
    public:
        /**
         * @brief Calculates the property tax based on the total value.
         * 
         * This method computes the property tax as 20% of the total value.
         * 
         * @param total The total value on which the property tax is calculated.
         * @return The calculated property tax.
         */
        int calculateTax(int total)
        {
            return (total * 0.2);            
        };
};

#endif
