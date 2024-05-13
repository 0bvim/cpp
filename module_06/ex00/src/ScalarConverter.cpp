#include "ScalarConverter.hpp"
#include "Defines.hpp"
#include <cctype>
#include <climits>
#include <cmath>
#include <iostream>
#include <math.h>
#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &rhs) { *this = rhs; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
  (void)rhs;
  return *this;
}

/**
 * @brief Verifies if a string contains a single digit character that is
 * printable.
 *
 * @param str The string to verify.
 * @return true if the string contains a single printable digit character, false
 * otherwise.
 */
static bool verifyOneDigit(const std::string &str) {
  if (str.size() == 1 && !std::isdigit(str[0]) && std::isprint(str[0])) {
    return true;
  }
  return false;
}

/**
 * @brief Checks if a string represents a float by checking if it ends with 'f'.
 *
 * @param str The string to check.
 * @return true if the string ends with 'f', false otherwise.
 */
static bool isFloat(const std::string &str) {
  return str[str.size() - 1] == 'f' ? true : false;
}

/**
 * @brief Checks additional conditions to verify if a float value is an exact
 * integer.
 *
 * @param f The float value to check.
 * @return true if the float value meets the conditions, false otherwise.
 */
static bool floatConditions(const float f) {
  if (!isinff(f) && (f == std::floor(f) || f == std::ceil(f)) &&
      std::abs(f - round(f)) < 0.001)
    return true;
  return false;
}

/**
 * @brief Checks additional conditions to verify if a double value is an exact
 * integer.
 *
 * @param d The double value to check.
 * @return true if the double value meets the conditions, false otherwise.
 */
static bool doubleConditions(const double d) {
  if (!isinff(d) && (d == std::floor(d) || d == std::ceil(d)) &&
      std::abs(d - round(d)) < 0.001)
    return true;
  return false;
}

void ScalarConverter::convert(const std::string &str) {
  char c;
  int i;
  float f;
  double d;

  if (verifyOneDigit(str)) {
    f = static_cast<float>(str[0]);
    d = static_cast<double>(f);
  } else if (isFloat(str)) {
    f = atof(str.c_str());
    d = static_cast<double>(f);
  } else {
    d = atof(str.c_str());
    f = static_cast<float>(d);
  }

  i = static_cast<int>(f);

  if (i < -128 || i > 127) {
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

  std::cout << MAGENTA("float: ");
  if (f == static_cast<int>(f) && floatConditions(f))
    std::cout << f << ".0f" << std::endl;
  else {
    if (isinf(f) && str[0] != '-')
      std::cout << "+";
    std::cout << f << "f" << std::endl;
  }

  std::cout << MAGENTA("double: ");
  if (d == static_cast<int>(d) && doubleConditions(d))
    std::cout << d << ".0" << std::endl;
  else {
    if (isinf(d) && str[0] != '-')
      std::cout << "+";
    std::cout << d << std::endl;
  }
}
