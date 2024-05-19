#include "Defines.hpp"
#include "RPN.hpp"
#include <exception>
#include <iostream>

static void usage(void) {
  NL;
  std::cerr << MAGENTA("Usage: ./bin/RPN \"<expression>\"") << std::endl;
}

void start_program(char *av) {
  try {
		RPN rpn(av);
		rpn.calculate();

  } catch (const std::exception &e) {
    std::cerr << RED("Error: ") << e.what();
  }
}

int main(int ac, char **av) {
  if (ac == 2)
    start_program(av[1]);
  else
    usage();

  return 0;
}
