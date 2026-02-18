#include "auditor.h"
#include <iostream>

bool Auditor::verifyAccount(const BankAccount &account)
{
  bool isValid = true;
  // Verify account number format (must be 10 digits)
  unsigned int length = account.accountNumber.length();
  if (length != 10)
  {
    std::cout << "Account number must be 10 digits. Got " << length << " instead." << std::endl;
    isValid = false;
  }
  for (char c : account.accountNumber)
  {
    if (!isdigit(c))
    {
      std::cout << "Invalid account number format: " << account.accountNumber << std::endl;
      isValid = false;
      break;
    }
  }

  // Access account balance and transaction count directly via friend relationship
  // Verify balance is non-negative
  if (account.accountBalance < 0)
  {
    std::cout << "Negative account balance: " << account.accountBalance << std::endl;
    isValid = false;
  }

  std::cout << "Total transactions: " << account.transactionCount << std::endl;
  std::cout << "Current balance: $" << account.accountBalance << std::endl;

  return isValid;
}