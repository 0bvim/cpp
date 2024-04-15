#include <cstdlib>
#include <iostream>
#include "Files.hpp"

int main (int argc, char *argv[]) {
	(void)argv;
	if (argc != 4) {
		std::cerr << "3 arguments needed: <file> <old string> <new string2>" << std::endl;
	} else {
		Files files(argv[1]);
		std::cout << files.fileReader() << std::endl;
	}
	return EXIT_SUCCESS;
}

