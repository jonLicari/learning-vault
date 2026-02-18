#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include <iostream>

class Ability
{
public:
  Ability(const std::string &name);
  // TODO: Ensure proper cleanup in the polymorphic class hierarchy
  ~Ability();
  
  virtual void use() const = 0; // Pure virtual
  virtual void describe() const;

protected:
  std::string abilityName;
};

#endif