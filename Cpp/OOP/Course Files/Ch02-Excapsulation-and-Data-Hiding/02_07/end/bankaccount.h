// bankaccount.h
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount
{
public:
  BankAccount(const std::string &number, float initialBalance);
  void deposit(float amount);
  void withdraw(float amount);
  void displayBalance() const;

private:
  friend class Auditor; // TODO: remove from starter

  std::string accountNumber;
  float accountBalance;
  // unsigned int transactionCount = 0;
  mutable unsigned int transactionCount = 0; // TODO: remove from starter
};

#endif