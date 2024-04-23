#include "ClapTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  ClapTrap blip("testTrap");

  blip.attack("YOU");
  blip.beRepaired(10);
  std::cout << blip.getHitPoints() << "hp\n"
            << blip.getEnergypoint() << "energy points" << std::endl;
  return EXIT_SUCCESS;
}
