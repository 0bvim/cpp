#include "ClapTrap.hpp"
#include <cstdlib>

int main(void) {
  ClapTrap blip("normal");

	blip.takeDamage(1);
	blip.beRepaired(2);
	blip.takeDamage(11);
	blip.takeDamage(1);

  return EXIT_SUCCESS;
}
