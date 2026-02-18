#include "bankaccount.h"
#include <iostream>

BankAccount::BankAccount(const std::string &number, float initialBalance)
{
  if (initialBalance < 0)
  {
    throw std::invalid_argument("Initial balance cannot be negative");
  }

  accountNumber = number;
  accountBalance = initialBalance;
}

void BankAccount::deposit(float amount)
{
  if (amount <= 0)
  {
    throw std::invalid_argument("Deposit amount must be positive");
  }
  accountBalance += amount;
  ++transactionCount;
}

void BankAccount::withdraw(float amount)
{
  if (amount <= 0)
  {
    throw std::invalid_argument("Withdrawal amount must be positive");
  }
  if (amount > accountBalance)
  {
    throw std::invalid_argument("Insufficient funds");
  }
  accountBalance -= amount;
  ++transactionCount;
}

void BankAccount::displayBalance() const
{
  ++transactionCount; // Viewing balance counts as a transaction

  std::cout << "Account: " << accountNumber << "\n"
            << "Balance: $" << accountBalance << "\n"
            << "Transactions: " << transactionCount << std::endl;
}