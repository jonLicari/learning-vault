#ifndef MELEE_ATTACK_H
#define MELEE_ATTACK_H

#include "ability.h"

class MeleeAttack : public Ability
{
public:
  MeleeAttack(const std::string &name, int force);
  ~MeleeAttack();

  // TODO: Override use()
  void use() const override;

  // TODO: Override describe()
  void describe() const override;

private:
  int impactForce;
};

#endif