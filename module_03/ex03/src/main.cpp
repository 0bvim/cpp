#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>
#include <iostream>

int main(void) {
  {
    DiamondTrap blep("anormal");

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
    blep.guardGate();
    blep.highFivesGuys();
    blep.whoAmI();
  }
  std::cout << std::endl;
  std::cout << "Tests done, now is time to fight." << std::endl;
  std::cout << std::endl;
  {
    ScavTrap fighterOne("Guile");
    FragTrap fighterTwo("Tom");
    DiamondTrap fighterThree("Maguila");

    fighterOne.attack("Tom");
    fighterTwo.takeDamage(fighterOne.getAttackDamage());
    fighterTwo.attack("Maguila");
    fighterThree.takeDamage(fighterTwo.getAttackDamage());
    fighterThree.attack("Tom");
    fighterOne.takeDamage(fighterThree.getAttackDamage());
    std::cout << "The fight ends cuz one fighter are in defensive mode "
              << "and the other guy are trying to make peace with a high five! "
                 "And fighter three don't know who he are."
              << std::endl;
    fighterOne.guardGate();
    fighterTwo.highFivesGuys();
    fighterThree.whoAmI();
  }

  return EXIT_SUCCESS;
}
