#include "defensiveability.h"

DefensiveAbility::DefensiveAbility(const std::string &name, int protection)
    // TODO: Initialize base class
    : protectionAmount(protection)
{
}

DefensiveAbility::~DefensiveAbility()
{
    std::cout << "\nDefensiveAbility object is being deleted." << std::endl;
}

// TODO: Override use()
// TODO: Override describe()