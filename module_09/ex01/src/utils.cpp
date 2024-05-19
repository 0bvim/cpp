#include "utils.h"
#include "Defines.hpp"
#include <cctype>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

std::string trim(const std::string &str) {
  std::string newStr = "";

  std::string::const_iterator start = str.begin();
  while (start != str.end() && std::isspace(*start)) {
    start++;
  }

  std::string::const_reverse_iterator end = str.rbegin();
  while (end.base() != start && std::isspace(*end)) {
    end++;
  }

  for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
    if (!::isspace(*it)) {
      newStr += *it;
    }
  }

  return newStr;
}

bool isOp(char c) { return c == '+' || c == '-' || c == '/' || c == '*'; }

bool validateInput(const std::string &str) {
  if (str.empty()) {
    throw std::invalid_argument("How you wanna calculate 'nothing'?");
  }
  std::string validate = trim(str);
  std::string::const_iterator it = validate.begin();

  for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
		OUTNL(*it);

    if (::isdigit(*it) || (isOp(*it) && !isOp(*(it + 1)))) {
      continue;
    } else if (::isdigit(*it)) {
      if (it + 1 != str.end() && ::isdigit(*(it + 1)))
        throw std::invalid_argument("Only numbers less than 10 allowed.");
    } else {
      throw std::invalid_argument("Only number and operator allowed.");
    }
  }

  if (isOp(*it)) {
    throw std::invalid_argument("Operation cannot be ther first element.");
  } else if (std::isdigit(*it) && isOp(*(it + 2))) {
    throw std::invalid_argument("You need to use 'number number + Operation'");
  }

  return true;
}
