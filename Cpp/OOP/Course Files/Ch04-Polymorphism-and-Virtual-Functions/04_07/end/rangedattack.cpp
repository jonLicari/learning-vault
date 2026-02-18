#include "rangedattack.h"

RangedAttack::RangedAttack(const std::string &name, int range)
    : Ability(name), rangeValue(range)
{
}

RangedAttack::~RangedAttack()
{
    std::cout << "\nRangedAttack object is being deleted." << std::endl;
}

void RangedAttack::use() const
{
    std::cout << "Firing heat vision beam!" << std::endl;
}

void RangedAttack::describe() const
{
    Ability::describe();
    std::cout << "Range: " << rangeValue << " meters" << std::endl;
}