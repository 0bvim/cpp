#include "Harl.hpp"
#include <cstdlib>

int main(int argc, char *argv[]) {
  Harl harl;

  if (argc == 2) {
    harl.complain(argv[1]);
  }

  return EXIT_SUCCESS;
}
