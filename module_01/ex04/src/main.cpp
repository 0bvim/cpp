#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

void replaceString(std::string file, std::string old, std::string replace) {
	(void)file;
	std::ifstream ifs("test");
	std::string content;
	std::string content2;
	while (ifs)
	{

	}
	ifs >> content >> content >> content;
	std::cout << "content of file:\n" << content << " " << content2 << std::endl;
	std::cout << "content of old: " << old << " content of new: " << replace << std::endl;
}
int main (int argc, char *argv[]) {
	(void)argv;
	if (argc != 4) {
		std::cerr << "3 arguments needed: <file> <old string> <new string2>" << std::endl;
	} else {
		replaceString(argv[1], argv[2], argv[3]);
		std::cout << "Correct arguments" << std::endl;
	}
	return EXIT_SUCCESS;
}

