#include "Defines.hpp"
#include "PmergeMe.hpp"
#include <exception>
#include <iostream>
#include <vector>

static void usage(void) {
  NL;
  std::cerr << MAGENTA("Usage: ./bin/PmergeMe \"<unsorted number sequence>\"")
            << std::endl;
}

void start_program(int ac, char **av) {
  try {
    Ford srt(validateAndProcessInput<std::vector<int> >(av, ac),
             validateAndProcessInput<std::list<int> >(av, ac));

		std::cout << GREEN("before: ");
		printSequence(srt.getVector());

		displayTime(srt.getVector(), "vector");
		printAfter = true;
		displayTime(srt.getList(), "list");

  } catch (const std::exception &e) {
    std::cerr << RED("Error: ") << e.what();
  }
}

int main(int ac, char **av) {
  if (ac > 2)
    start_program(ac, av);
  else
    usage();

  return 0;
}
