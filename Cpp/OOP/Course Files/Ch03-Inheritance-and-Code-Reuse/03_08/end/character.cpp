#include "character.h"

Character::Character(const std::string &name, int health)
    : name(name), health(health)
{
}

void Character::attack() const
{
  std::cout << name << " attacks for " << BASE_DAMAGE << " damage!" << std::endl;
}

void Character::displayStats() const
{
  std::cout << "Character Stats:\n"
            << "Name: " << name << "\n"
            << "Health: " << health << std::endl;
}
