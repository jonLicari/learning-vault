#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include <iostream>

class Ability
{
public:
  Ability(const std::string &name);
  virtual ~Ability();

  virtual void use() const = 0; // Pure virtual
  virtual void describe() const;

protected:
  std::string abilityName;
};

#endif