#include "Defines.hpp"
#include "whatever.hpp"
#include <iostream>

void intTest(void) {
  int a = 2;
  int b = 3;

  NL;
  std::cout << RED("Initial value of a: ") << a << std::endl;
  std::cout << RED("Initial value of b: ") << b << std::endl;

  NL;
  std::cout << YELLOW("Swaping values of 'a' and 'b'.") << std::endl;
  ::swap(a, b);

  std::cout << GREEN("Value of a after swap: " << a) << std::endl;
  std::cout << GREEN("Value of b after swap: " << b) << std::endl;

  NL;

  std::cout << YELLOW("Min value between 'a' and 'b'") << std::endl;

  std::cout << GREEN("min( a, b ) = ") << ::min(a, b) << std::endl;
  NL;

  std::cout << YELLOW("Max value between 'a' and 'b'") << std::endl;
  std::cout << GREEN("max( a, b ) = ") << ::max(a, b) << std::endl;
  NL;
}

void strTest(void) {
  std::string c = "chaine1";
  std::string d = "chaine2";
  std::cout << RED("Initial value of c: ") << c << std::endl;
  std::cout << RED("Initial value of d: ") << d << std::endl;
  NL;

  std::cout << YELLOW("Swaping values of 'c' and 'd'.") << std::endl;
  ::swap(c, d);
  std::cout << GREEN("Value of c after swap: " << c) << std::endl;
  std::cout << GREEN("Value of d after swap: " << d) << std::endl;
  NL;

  std::cout << YELLOW("Min value between 'c' and 'd'") << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  NL;

  std::cout << YELLOW("Max value between 'c' and 'd'") << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
}

void subjectTest(void) {
  NL;
  std::cout << BLACK("Test provided by subject") << std::endl;
  int a = 2;
  int b = 3;
  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
}

int main(void) {
  intTest();
  strTest();
  subjectTest();
  return 0;
}
