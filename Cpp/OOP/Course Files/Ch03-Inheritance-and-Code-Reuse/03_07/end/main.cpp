#include "warrior.h"

int main()
{
  Warrior warrior("Oryn", 100, 15); // name, health, strength
  warrior.addItem("Sword");
  warrior.addItem("Shield");

  warrior.displayStats();
  warrior.attack();

  return 0;
}