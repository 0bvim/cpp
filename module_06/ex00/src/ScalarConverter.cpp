#include "ScalarConverter.hpp"
#include "Defines.hpp"
#include <cctype>
#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &rhs) { *this = rhs; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
  (void)rhs;
  return *this;
}

static bool verifyOneDigit(const std::string &str) {
  if (str.size() == 1 && !std::isdigit(str[0]) && std::isprint(str[0])) {
    return true;
  }
  return false;
}

static bool isFloat(const std::string &str) {
  return str[str.size() - 1] == 'f' ? true : false;
}

void ScalarConverter::convert(const std::string &str) {
  char c;
  int i;
  float f;
  double d;

  if (verifyOneDigit(str)) {
    f = static_cast<float>(str[0]);
    d = static_cast<double>(str[0]);
  } else if (isFloat(str)) {
    std::istringstream(str) >> f;
    d = static_cast<double>(f);
  } else {
    std::istringstream(str) >> d;
    f = static_cast<float>(d);
  }

  i = static_cast<int>(f);

  if (isascii(i)) {
    std::cout << RED("char: impossible") << std::endl;
  } else if (!std::isprint(i)) {
    std::cout << RED("char: Non displayable") << std::endl;
  } else {
    c = static_cast<char>(i);
    std::cout << GREEN("char: '") << c << "'" << std::endl;
  }

  if (std::isnan(d) || d > INT_MAX || d < INT_MIN) {
    std::cout << RED("int: impossible") << std::endl;
  } else {
    std::cout << MAGENTA("int: ") << i << std::endl;
  }

  std::cout << CYAN("float: ") << f << std::endl;
  if (!isinff(f) && (f == std::floor(f) || f == std::ceil(f))) {
    std::cout << ".0" << std::endl;
  }

  std::cout << BLUE("double: ") << d << std::endl;
  if (!isinf(d) && (d == std::floor(d) || d == std::ceil(d))) {
    std::cout << ".0" << std::endl;
  }
}
