#include "Zombie.hpp"
#include <cstdlib>

int main(void) {
  Zombie *zombie = newZombie("Lila");
  Zombie zombie2;

  zombie2.setName("Nivi");
  randomChump("Stete");
  zombie2.announce();
  zombie->announce();
  delete zombie;

  return EXIT_SUCCESS;
}
