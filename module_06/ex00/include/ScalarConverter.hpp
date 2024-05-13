#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

/**
 * @brief Class for converting scalar values.
 * 
 * This class provides functionality to convert scalar values represented as strings.
 */
class ScalarConverter {
private:
  ScalarConverter(); // Private constructor to prevent instantiation
  ScalarConverter(ScalarConverter const &rhs); // Private copy constructor
  ScalarConverter &operator=(ScalarConverter const &rhs); // Private assignment operator

public:
  /**
   * @brief Destructor.
   */
  ~ScalarConverter();

  /**
   * @brief Convert the given string to a scalar value.
   * 
   * This function converts the given string to a scalar value and prints the result.
   * 
   * @param str The string to be converted.
   */
  void convert(const std::string &str);
};

#endif // SCALARCONVERTER_HPP
