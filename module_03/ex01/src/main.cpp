#include "ClapTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  ClapTrap blip("normal");

  std::cout << "Messages tests" << std::endl;
  blip.attack("You");
  blip.attack("");
  blip.takeDamage(-1);
  blip.beRepaired(-1);

  std::cout << std::endl;
  std::cout << "Health Points tests" << std::endl;

  blip.takeDamage(1);
  blip.beRepaired(2);
  blip.takeDamage(11);
  blip.takeDamage(1);

  std::cout << std::endl;
  std::cout << "Energy tests" << std::endl;

  /* setuping for energy tests */
  blip.setEnergyPoint(0);
  blip.setHitPoints(10);

  blip.attack("You again");
  blip.beRepaired(1);
  blip.attack("A ghost");

  return EXIT_SUCCESS;
}
