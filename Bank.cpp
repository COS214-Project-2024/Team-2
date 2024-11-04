#include "Bank.h"

/**
 * @brief Gets the current balance.
 * 
 * @return The current balance in the account.
 */
int Bank::get()
{
    return balance;
}

/**
 * @brief Increases the balance by a specified amount.
 * 
 * This method increments the account balance and adjusts the budget accordingly.
 * 
 * @param amount The amount to add to the balance.
 */
void Bank::increment(int amount)
{
    balance += amount;
    correctBudget();
}

/**
 * @brief Decreases the balance by a specified amount.
 * 
 * This method decrements the account balance and adjusts the budget accordingly.
 * 
 * @param amount The amount to subtract from the balance.
 */
void Bank::decrement(int amount)
{
    balance -= amount;
    correctBudget();
}

/**
 * @brief Adjusts the budget based on the current balance.
 * 
 * This method recalculates the budget as 80% of the current balance.
 */
void Bank::correctBudget()
{
    budget = balance * 0.8;
}
