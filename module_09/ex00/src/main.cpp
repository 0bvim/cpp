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

  Exchange btc;

  try {
    btc.openFile(av);
  } catch (std::exception &e) {
    OUTNL(RED("Catch error: ")) << e.what() << std::endl;
  }
}

int main(int ac, char **av) {
  if (ac == 2)
    start_program(av[1]);
  usage();

  return 0;
}
