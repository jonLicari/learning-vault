#include "equipment.h"

void Equipment::addItem(const std::string &item)
{
  inventory.push_back(item);
}

void Equipment::displayInventory() const
{
  std::cout << "Equipment:" << std::endl;
  for (const auto &item : inventory)
  {
    std::cout << "- " << item << std::endl;
  }
}