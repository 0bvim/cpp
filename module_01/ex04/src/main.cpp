#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

void replaceString(std::string file, std::string old, std::string new) {
	if (std::ifstream(file))
}
int main (int argc, char *argv[]) {
	(void)argv;
	if (argc != 4) {
		std::cerr << "3 arguments needed: <file> <old string> <new string2>" << std::endl;
	} else {
		std::cout << "Correct arguments" << std::endl;
	}
	return EXIT_SUCCESS;
}

