#include "Replace.hpp"
#include <string>
#include <iostream>
#include <fstream>

Replace::Replace(std::string original, std::string search, std::string replace, std::string fileName)
    : _toReplace(original), _search(search), _replace(replace), _fileName(fileName) {}

Replace::~Replace() {}

void Replace::replaceOut() {
  size_t pos = 0;

  while ((pos = _toReplace.find(_search, pos)) != std::string::npos) {
    _toReplace = _toReplace.substr(0, pos) + _replace +
                 _toReplace.substr(pos + _search.length());
    pos += _replace.length();
  }
	std::ofstream outputFile((_fileName + ".replace").c_str());
	if (outputFile.is_open()) {
		outputFile << _toReplace;
		outputFile.close();
	} else {
		std::cerr << "Error: Unable to open file for writing." << std::endl;
	}
}
