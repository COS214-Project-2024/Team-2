#ifndef TAXSTRATEGY_H
#define TAXSTRATEGY_H


class TaxStrategy
{
    public:
        virtual double calculateTax(int total) = 0;
};

#endif