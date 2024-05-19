#include "utils.h"
#include "Defines.hpp"
#include <cctype>
#include <stdexcept>
#include <string>

std::string trim(const std::string &str) {
  std::string::const_iterator start = str.begin();
  while (start != str.end() && std::isspace(*start)) {
    start++;
  }

  std::string::const_reverse_iterator end = str.rbegin();
  while (end.base() != start && std::isspace(*end)) {
    end++;
  }
  return std::string(start, end.base());
}

bool isOp(char c) { return c == '+' || c == '-' || c == '/' || c == '*'; }

bool validateInput(const std::string &str) {
  if (str.empty()) {
    throw std::invalid_argument("How you wanna calculate 'nothing'?");
  }

	for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
		if (!std::isdigit(*it) || !isOp(*it)) {
			throw std::invalid_argument("Invalid input.");
		}
	}


  return true;
}
