#include "Fixed.hpp"
#include <iostream>

void testOperators(void) {
  if (Fixed(2) > Fixed(1))
    std::cout << "test greater" << std::endl;
  if (Fixed(1) < Fixed(2))
    std::cout << "test lesser" << std::endl;
  if (Fixed(2) >= Fixed(1))
    std::cout << "test greater equal" << std::endl;
  if (Fixed(1) <= Fixed(1))
    std::cout << "test lesser equal" << std::endl;
  if (Fixed(2) == Fixed(2))
    std::cout << "test equal" << std::endl;
  if (Fixed(2) != Fixed(1))
    std::cout << "test different" << std::endl;
}

void testIncrement(Fixed &a, Fixed const &b) {
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;
}

void testArithmeticOperators(void) {

  std::cout << "Sum 2 + 3 = " << (Fixed(2) + Fixed(3)) << std::endl;
  std::cout << "Sub 2 - 3 = " << (Fixed(2) - Fixed(3)) << std::endl;
  std::cout << "Div 2 / 3 = " << (Fixed(2) / Fixed(3)) << std::endl;
  std::cout << "Mult 2 * 3 = " << (Fixed(2) * Fixed(3)) << std::endl;
}
