#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
	{
		FragTrap blep("anormal");

		std::cout << "Messages tests" << std::endl;
		std::cout << blep.getName();
		blep.attack("You");
		blep.attack("");
		blep.takeDamage(-1);
		blep.beRepaired(-1);

		std::cout << std::endl;
		std::cout << "Health Points tests" << std::endl;

		blep.takeDamage(1);
		blep.beRepaired(2);
		blep.takeDamage(11);
		blep.takeDamage(1);

		std::cout << std::endl;
		std::cout << "Energy tests" << std::endl;

		/* setuping for energy tests */
		blep.setEnergyPoint(0);
		blep.setHitPoints(10);

		blep.attack("You again");
		blep.beRepaired(1);
		blep.attack("A ghost");
		blep.highFivesGuys();
	}
	std::cout << std::endl;
	std::cout << "Tests done, now is time to fight." << std::endl;
	std::cout << std::endl;
	{
		ScavTrap fighterOne("Guile");
		FragTrap fighterTwo("Tom");

		fighterOne.attack("Tom");
		fighterTwo.takeDamage(fighterOne.getAttackDamage());
		fighterTwo.attack("Guile");
		fighterOne.takeDamage(fighterTwo.getAttackDamage());
		fighterOne.guardGate();
		fighterTwo.highFivesGuys();
		std::cout << "The fight ends cuz one fighter are in defensive mode "
							<< "and the other guy are trying to make peace with a high five!" << std::endl;
	}

  return EXIT_SUCCESS;
}
