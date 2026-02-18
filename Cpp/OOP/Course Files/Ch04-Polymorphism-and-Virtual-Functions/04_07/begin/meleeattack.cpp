// meleeattack.cpp
#include "meleeattack.h"

MeleeAttack::MeleeAttack(const std::string &name, int force)
    // TODO: Initialize base class
    : impactForce(force)
{
}

MeleeAttack::~MeleeAttack()
{
    std::cout << "\nMeleeAttack object is being deleted." << std::endl;
}

// TODO: Override use()
// TODO: Override describe()