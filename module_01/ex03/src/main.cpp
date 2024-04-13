#include <cstdlib>
#include <iostream>
#include <HumanA.hpp>

int main(void) {
	HumanA human;

	human.setName("Daniboy");
	human.setWeaponType("Britadeira");
	std::cout << "My name is " << human.getName() << std::endl;
	std::cout << "Weapon that I use to f** is the biggest " << human.getWeaponType() << std::endl;

  return EXIT_SUCCESS;
}
