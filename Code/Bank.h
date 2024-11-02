#ifndef BANK_H
#define BANK_H

class Bank
{
    private:
        int balance = 1500;
        int budget = balance * 0.8;
    
    public:
        int get();
        void increment(int amount);
        void decrement(int amount);
        void correctBudget();
};

#endif
