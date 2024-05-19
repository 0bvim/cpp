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

void RPN::validateInput(const std::string &str) {
  if (str.empty()) {
    throw std::invalid_argument("How you wanna calculate 'nothing'?");
  } else if (doubleDigit(str)) {
    throw std::invalid_argument(
        "Only numbers between 0 and 9. And no double operators.");
  }

  std::string validate = trimInternSpaces(str);
  std::string::const_iterator it = validate.begin();

  for (std::string::const_iterator it = validate.begin(); it != validate.end();
       ++it) {
    if (::isdigit(*it) || isOp(*it)) {
      continue;
    } else {
      throw std::invalid_argument("Only number and operator allowed.");
    }
  }

  if (isOp(*it)) {
    throw std::invalid_argument("Operation cannot be ther first element.");
  } else if (std::isdigit(*it) && isOp(*(it + 1))) {
    throw std::invalid_argument("You need to use 'number number + Operation'");
  }

  this->_input = validate;
}

int RPN::calculate(void) {

  OUTNL(this->_input);
  return 1;
}
