#include "RPN.hpp"

RPN::RPN() : _input(""), _stack() {}

RPN::RPN(const std::string input) : _input(input) {}

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
