#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <vector>
#include <string>
#include <iostream>

class Equipment
{
public:
  void addItem(const std::string &item);
  void displayInventory() const;

private:
  std::vector<std::string> inventory;
};

#endif