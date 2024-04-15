#include "Files.hpp"
#include <fstream>
#include <iostream>
#include <string>

Files::Files(const std::string& name) : fileName(name) {}

Files::~Files() {}

std::string Files::fileReader() {
	std::ifstream file(fileName.c_str());
	if (!file.is_open()) {
		std::cerr << "Error opening the file." << std::endl;
		return "";
	}
}

