#include "Pessoa.hpp"
#include <iostream>

Pessoa::Pessoa() : _age(0) {
	std::cout << "Construtor de pessoa foi chamado" << std::endl;
}

Pessoa::~Pessoa() {
	std::cout << "Destrutor de pessoa foi chamado" << std::endl;
}

void Pessoa::setName(const std::string name) {
	this->_name = name;
}

std::string Pessoa::getName(void) const {
	if (_name.empty())
		return "Not named yet.";
	return this->_name;
}

