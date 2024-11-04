#ifndef TAXSTRATEGY_H
#define TAXSTRATEGY_H

/**
 * @class TaxStrategy
 * @brief Abstract base class for different tax calculation strategies.
 * 
 * This class provides an interface for calculating taxes based on a 
 * given total amount. Derived classes should implement specific tax 
 * calculation strategies.
 */
class TaxStrategy
{
    public:
        /**
         * @brief Pure virtual function to calculate tax.
         * 
         * This function must be implemented by derived classes to provide
         * the specific tax calculation logic.
         * 
         * @param total The total amount on which tax is to be calculated.
         * @return The calculated tax amount.
         */
        virtual int calculateTax(int total) = 0;
};

#endif
