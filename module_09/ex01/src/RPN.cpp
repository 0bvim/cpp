#include "RPN.hpp"
#include "Defines.hpp"
#include "utils.h"
#include <exception>
#include <iostream>
#include <ostream>

RPN::RPN() : _input(""), _stack() {}

RPN::RPN(const std::string input) : _input(input) {
	try {
	validateInput(this->_input);
	} catch (const std::exception &e) {
		std::cerr << RED(e.what()) << std::endl;
	}
}

RPN::~RPN() {}

RPN::RPN(const RPN &rhs) {
  this->_input = rhs._input;
  this->_stack = rhs._stack;
}

RPN &RPN::operator=(const RPN &rhs) {
  if (this != &rhs) {
    this->_input = rhs._input;
    this->_stack = rhs._stack;
  }
  return *this;
}

const char *RPN::InvalidExpressionException::what() const throw() {
  return "Error";
}

int RPN::calculate(void) { return 0; }
