#include "Bank.h"

int Bank::get()
{
    return balance;
}

void Bank::increment(int amount)
{
    balance += amount;
    correctBudget();
}

void Bank::decrement(int amount)
{
    balance -= amount;
    correctBudget();
}

void Bank::correctBudget()
{
    budget = balance * 0.8;
}