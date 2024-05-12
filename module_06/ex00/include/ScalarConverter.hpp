#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(ScalarConverter const &rhs);
  ScalarConverter &operator=(ScalarConverter const &rhs);

public:
  ~ScalarConverter();
  static void convert(const std::string &str);
};

#endif // SCALARCONVERTER_HPP
