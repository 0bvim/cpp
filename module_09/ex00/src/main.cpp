#include "BitcoinExchange.hpp"
#include "Defines.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

void start_program(char *av) {

  std::ifstream inputFile(av);
  if (!inputFile.is_open()) {
    throw std::logic_error("Error opening file");
  }
  OUT(RED("test text")) << std::endl;
  OUTNL(YELLOW("another text test"));
}

int main(int ac, char **av) {
  if (ac == 2)
    start_program(av[1]);

  return 0;
}
