#include "defensiveability.h"

DefensiveAbility::DefensiveAbility(const std::string &name, int protection)
    : Ability(name), protectionAmount(protection)
{
}

DefensiveAbility::~DefensiveAbility()
{
    std::cout << "\nDefensiveAbility object is being deleted." << std::endl;
}

void DefensiveAbility::use() const
{
    std::cout << "Activating defensive force field!" << std::endl;
}

void DefensiveAbility::describe() const
{
    Ability::describe();
    std::cout << "Protection: " << protectionAmount << std::endl;
}