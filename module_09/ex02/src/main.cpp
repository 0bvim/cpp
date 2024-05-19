#include "Defines.hpp"
#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

static void usage(void) {
  NL;
  std::cerr << MAGENTA("Usage: ./bin/PmergeMek \"<unsorted number sequence>\"") << std::endl;
}

void start_program(int ac, char **av) {
  try {
		Ford srt;

		hasDuplicates(srt.inputValidation(av, ac));

    (void)av;
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
