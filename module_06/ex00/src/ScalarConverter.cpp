#include "ScalarConverter.hpp"
#include "Defines.hpp"
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
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

static void converter(const std::string &str) {
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

}
