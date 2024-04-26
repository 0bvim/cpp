#include "ScavTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
	ScavTrap blop("anormal");

  std::cout << "Messages tests" << std::endl;
  blop.attack("You");
  blop.attack("");
  blop.takeDamage(-1);
  blop.beRepaired(-1);
 
  std::cout << std::endl;
  std::cout << "Health Points tests" << std::endl;

  blop.takeDamage(1);
  blop.beRepaired(2);
  blop.takeDamage(11);
  blop.takeDamage(1);

  std::cout << std::endl;
  std::cout << "Energy tests" << std::endl;

  /* setuping for energy tests */
  blop.setEnergyPoint(0);
  blop.setHitPoints(10);

  blop.attack("You again");
  blop.beRepaired(1);
  blop.attack("A ghost");
	blop.guardGate();

  return EXIT_SUCCESS;
}
