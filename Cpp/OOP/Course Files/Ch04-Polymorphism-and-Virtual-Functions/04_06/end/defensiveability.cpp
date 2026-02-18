#include "defensiveability.h"

DefensiveAbility::DefensiveAbility(const std::string &name, int protection)
    // TODO: Initialize base class
    : protectionAmount(protection), Ability(name)
{
}

DefensiveAbility::~DefensiveAbility()
{
    std::cout << "\nDefensiveAbility object is being deleted." << std::endl;
}

// TODO: Override use()
void DefensiveAbility::use() const {
    std::cout << "Activating defensive force field!" << std::endl;
}

// TODO: Override describe()
void DefensiveAbility::describe() const {
    Ability::describe();
    std::cout << "Protection: " << protectionAmount << std::endl;
}