#ifndef BANK_H
#define BANK_H

/**
 * @brief Represents a bank account for managing a citizen's funds.
 * 
 * The Bank class provides functionality to get the current balance, increment or decrement
 * the balance, and automatically adjust the budget based on the balance.
 */
class Bank {
    private:
        int balance = 1500; /**< The current balance of the account */
        int budget = balance * 0.8; /**< The budget calculated as 80% of the balance */

    public:
        /**
         * @brief Gets the current balance.
         * 
         * @return The current balance in the account.
         */
        int get();

        /**
         * @brief Increases the balance by a specified amount.
         * 
         * This method increments the account balance and adjusts the budget accordingly.
         * 
         * @param amount The amount to add to the balance.
         */
        void increment(int amount);

        /**
         * @brief Decreases the balance by a specified amount.
         * 
         * This method decrements the account balance and adjusts the budget accordingly.
         * 
         * @param amount The amount to subtract from the balance.
         */
        void decrement(int amount);

        /**
         * @brief Adjusts the budget based on the current balance.
         * 
         * This method recalculates the budget as 80% of the current balance.
         */
        void correctBudget();
};

#endif
