#ifndef RANGED_ATTACK_H
#define RANGED_ATTACK_H

#include "ability.h"

class RangedAttack : public Ability
{
public:
  RangedAttack(const std::string &name, int range);
  ~RangedAttack();

  void use() const override;
  void describe() const override;

private:
  int rangeValue; // Range in meters
};

#endif