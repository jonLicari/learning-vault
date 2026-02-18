#ifndef WARRIOR_H
#define WARRIOR_H

#include "character.h"
#include "equipment.h"

// TODO: Inherit from Character, use composition to integrate Equipment behavior
class Warrior
{
public:
  Warrior(const std::string &name, int health, int strength);
  void attack() const;       // TODO: Override to include strength bonus
  void displayStats() const; // TODO: Override to show strength and equipment
  void addItem(const std::string &item);

private:
  int strength;
  // TODO: Add Equipment member
};

#endif