#include "Files.hpp"

Files::Files(){}

Files::~Files(){}

void Files::setFileName(std::string const name) {
	this->_fileName = name;
}

std::string Files::getFileName() {
	return this->_fileName;
}

