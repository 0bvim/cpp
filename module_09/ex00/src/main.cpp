#include "BitcoinExchange.hpp"
#include "Defines.hpp"
#include <exception>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

static void usage(void) {
  NL;
  std::cerr << MAGENTA("Usage: ./bin/btc <filename>") << std::endl;
}

void start_program(char *av) {
  try {
    Exchange btc(av);
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
