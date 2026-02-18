#ifndef MELEE_ATTACK_H
#define MELEE_ATTACK_H

#include "ability.h"

class MeleeAttack : public Ability
{
public:
  MeleeAttack(const std::string &name, int force);
  ~MeleeAttack();

  // TODO: Override use()
  // TODO: Override describe()
private:
  int impactForce;
};

#endif