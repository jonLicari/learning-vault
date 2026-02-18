#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>

class Character
{
public:
  Character(const std::string &name, int health);
  void attack() const;
  void displayStats() const;

protected:
  std::string name;
  int health;
  static const int BASE_DAMAGE = 10;
};

#endif