#include "Defines.hpp"
#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

void testChar() {
  std::cout << std::endl;
  std::cout << YELLOW("Testing char: 'A'") << std::endl;
  ScalarConverter::convert("A");

  std::cout << std::endl;
  std::cout << YELLOW("Testing char: '0'") << std::endl;
  ScalarConverter::convert("0");

  std::cout << std::endl;
  std::cout << YELLOW("Testing char: '?'") << std::endl;
  ScalarConverter::convert("?");

  std::cout << std::endl;
  std::cout << YELLOW("Testing char: ' '") << std::endl;
  ScalarConverter::convert(" ");

  std::cout << std::endl;
  std::cout << YELLOW("Testing char: '\\n'") << std::endl;
  ScalarConverter::convert("\n");

  std::cout << std::endl;
  std::cout << YELLOW("Testing char: '.'") << std::endl;
  ScalarConverter::convert(".");
}

void testInt() {
  std::cout << std::endl;
  std::cout << YELLOW("Testing int: '42'") << std::endl;
  ScalarConverter::convert("42");

  std::cout << std::endl;
  std::cout << YELLOW("Testing int: '-1234'") << std::endl;
  ScalarConverter::convert("-1234");

  std::cout << std::endl;
  std::cout << YELLOW("Testing int: '2147483647'") << std::endl;
  ScalarConverter::convert("2147483647");

  std::cout << std::endl;
  std::cout << YELLOW("Testing int: '-2147483648'") << std::endl;
  ScalarConverter::convert("-2147483648");
}

void testFloat() {
  std::cout << std::endl;
  std::cout << YELLOW("Testing float: '42.00001f'") << std::endl;
  ScalarConverter::convert("42.00001f");

  std::cout << std::endl;
  std::cout << YELLOW("Testing float: '-1234.5678f'") << std::endl;
  ScalarConverter::convert("-1234.5678f");

  std::cout << std::endl;
  std::cout << YELLOW("Testing float: '3.14159f'") << std::endl;
  ScalarConverter::convert("3.14159f");

  std::cout << std::endl;
  std::cout << YELLOW("Testing float: '-1.2345678e5f'") << std::endl;
  ScalarConverter::convert("-1.2345678e5f");

  std::cout << std::endl;
  std::cout << YELLOW("Testing float: 'inf'") << std::endl;
  ScalarConverter::convert("inf");

  std::cout << std::endl;
  std::cout << YELLOW("Testing float: '-inf'") << std::endl;
  ScalarConverter::convert("-inf");
}

void testDouble() {
  std::cout << std::endl;
  std::cout << YELLOW("Testing double: '42.00001'") << std::endl;
  ScalarConverter::convert("42.00001");

  std::cout << std::endl;
  std::cout << YELLOW("Testing double: '-1234.5678'") << std::endl;
  ScalarConverter::convert("-1234.5678");

  std::cout << std::endl;
  std::cout << YELLOW("Testing double: '3.14159'") << std::endl;
  ScalarConverter::convert("3.14159");

  std::cout << std::endl;
  std::cout << YELLOW("Testing double: '-1.2345678e5'") << std::endl;
  ScalarConverter::convert("-1.2345678e5");

  std::cout << std::endl;
  std::cout << YELLOW("Testing double: 'inf'") << std::endl;
  ScalarConverter::convert("inf");

  std::cout << std::endl;
  std::cout << YELLOW("Testing double: '-inf'") << std::endl;
  ScalarConverter::convert("-inf");
}

int main(int argc, char *argv[]) {

  if (argc != 2) {
    std::cout << RED("Usage: ") << YELLOW("./convert <arg>") << std::endl;
    return EXIT_FAILURE;
  }

  ScalarConverter::convert(argv[1]);

  std::string answer;
  std::cout << "Do you wanna run my own tests? [Y/n]" << std::endl;
  std::getline(std::cin, answer);
  if (!answer.compare("y") || !answer.compare("Y")) {
    testChar();
    testInt();
    testFloat();
    testDouble();
  } else {
    std::cout << "Thank you!" << std::endl;
  }

  return 0;
}
