#include "Files.hpp"
#include <fstream>
#include <iostream>
#include <string>

Files::Files(const std::string &name) : _fileName(name) {}

Files::~Files() {}

std::string Files::fileReader() {
  std::string line;
  std::ifstream file(_fileName.c_str());

  if (!file.is_open()) {
    std::cerr << "Error opening the file." << std::endl;
    return "";
  }
  while (std::getline(file, line)) {
    _content += line + "\n";
  }
	file.close();
  return _content;
}
