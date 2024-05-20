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

    std::vector<int> a(srt.getVector());
    std::list<int> b(srt.getList());

		std::cout << "vector: ";
    for (size_t i = 0; i < a.size(); ++i) {
      std::cout << a[i] << " ";
    }

		NL;

    std::cout << "list: ";
		for (std::list<int>::iterator it = b.begin(); it != b.end(); ++it) {
      std::cout << *it << " ";
		}

		NL;

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
