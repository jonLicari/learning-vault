// ability.cpp
#include "ability.h"

Ability::Ability(const std::string &name) : abilityName(name) {}

Ability::~Ability()
{
  std::cout << "Ability object is being deleted." << std::endl;
}

void Ability::describe() const
{
  std::cout << "Ability: " << abilityName << std::endl;
}