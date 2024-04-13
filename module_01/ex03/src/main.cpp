#include <HumanA.hpp>
#include <HumanB.hpp>
#include <Weapon.hpp>
#include <cstdlib>

int main() 
{
  {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    club.setType("Crude umbral mace");
    bob.attack();
    club.setType("Soulmaimer");
    bob.attack();
  }
  {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
		jim.attack();
		jim.attack();
		jim.attack();
    jim.setWeapon(club);
    jim.attack();
    club.setType("sword");
    jim.attack();
    club.setType("axe");
    jim.attack();
    club.setType("morning star");
    jim.attack();
  }
  return EXIT_SUCCESS;
}
