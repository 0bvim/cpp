#include "Zombie.hpp"
#include <cstdlib>

int main(void) {
  Zombie *horde;

  horde = zombieHorde(5, "Nancy");
  for (int i = 0; i < 5; ++i) {
    horde[i].announce();
  }
  delete[] horde;
  return EXIT_SUCCESS;
}
