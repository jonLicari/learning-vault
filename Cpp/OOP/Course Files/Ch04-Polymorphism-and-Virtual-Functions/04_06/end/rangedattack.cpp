#include "rangedattack.h"

RangedAttack::RangedAttack(const std::string &name, int range)
    // TODO: Initialize base class
    : rangeValue(range), Ability(name)
{
}

RangedAttack::~RangedAttack() {
    std::cout << "\nRangedAttack object is being deleted." << std::endl; 
}

// TODO: Override use()
void RangedAttack::use() const {
    std::cout << "Firing " << abilityName << " beam!" << std::endl;
}

// TODO: Override describe()
void RangedAttack::describe() const {
    Ability::describe();
    std::cout << "Range: " << rangeValue << " meters" << std::endl;
}