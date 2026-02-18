#include "rangedattack.h"
#include "meleeattack.h"
#include "defensiveability.h"
#include <vector>

int main()
{
  std::vector<Ability *> abilities;
  abilities.push_back(new RangedAttack("Heat Vision", 50));
  abilities.push_back(new MeleeAttack("Super Strength", 30));
  abilities.push_back(new DefensiveAbility("Force Field", 20));

  for (const Ability *ability : abilities)
  {
    ability->describe();
    ability->use();
    std::cout << std::endl;
  }

  // Clean up
  for (Ability *ability : abilities)
  {
    delete ability;
  }

  return 0;
}