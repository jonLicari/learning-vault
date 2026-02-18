#include "warrior.h"

Warrior::Warrior(const std::string &name, int health, int strength)
    : Character(name, health), strength(strength)
{
}

void Warrior::attack() const
{
  int totalDamage = BASE_DAMAGE + strength;
  std::cout << name << " attacks for " << totalDamage
            << " damage! (" << BASE_DAMAGE << " base + "
            << strength << " strength)" << std::endl;
}

void Warrior::displayStats() const
{
  Character::displayStats(); // Show base stats first
  std::cout << "Strength: " << strength << std::endl;
  equipment.displayInventory();
}

void Warrior::addItem(const std::string &item)
{
  equipment.addItem(item);
}