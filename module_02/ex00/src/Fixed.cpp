#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _fixedValue(0) {
  std::cout << "Class constructor called." << std::endl;
}

Fixed::Fixed(Fixed const &src) {
  std::cout << "Copy Constructor Called" << std::endl;
	*this = src;
  return;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
  std::cout << "Assignment operator called" << std::endl;
  if (this != &rhs) {
    this->_fixedValue = rhs.getRawBits();
  }
  return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits function called." << std::endl;
	return this->_raw;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits function called." << std::endl;
	this->_fixedValue = raw;
}

Fixed::~Fixed(void) { std::cout << "Destructor called." << std::endl; }
