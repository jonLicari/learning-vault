#include "warrior.h"

Warrior::Warrior(const std::string &name, int health, int strength)
    : Character(name, health), strength(strength)
{
}

void Warrior::attack() const
{
  // TODO: Implement attack including strength bonus
}

void Warrior::displayStats() const
{
  // TODO: Implement stats display including strength and equipment
}

void Warrior::addItem(const std::string &item)
{
  // TODO: Use Equipment member to add item
}