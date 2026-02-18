#include "rangedattack.h"

RangedAttack::RangedAttack(const std::string &name, int range)
    // TODO: Initialize base class
    : rangeValue(range)
{
}

RangedAttack::~RangedAttack()
{
    std::cout << "\nRangedAttack object is being deleted." << std::endl;
}

// TODO: Override use()
// TODO: Override describe()