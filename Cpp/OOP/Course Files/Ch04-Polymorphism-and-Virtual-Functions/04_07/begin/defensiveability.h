#ifndef DEFENSIVE_ABILITY_H
#define DEFENSIVE_ABILITY_H

#include "ability.h"

class DefensiveAbility : public Ability
{
public:
  DefensiveAbility(const std::string &name, int protection);
  ~DefensiveAbility();

  // TODO: Override use()
  // TODO: Override describe()

private:
  int protectionAmount; // Amount of protection provided
};

#endif