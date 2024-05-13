#include <cstdlib>
#include <iostream>
#include "Defines.hpp"
#include "ScalarConverter.hpp"

int main (int argc, char *argv[]) {
	
	if (argc != 2) {
		std::cout << RED("Usage: ") << YELLOW("./convert <arg>") << std::endl;
		return EXIT_FAILURE;
	}

	ScalarConverter::convert(argv[1]);

	return 0;
}
