#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void) : _fixedValue(0) {
  std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const int iraw) : _fixedValue(iraw * (1 << Fixed::_raw)) {
  std::cout << "Int constructor called." << std::endl;
}

Fixed::Fixed(const float fraw)
    : _fixedValue(roundf(fraw * (1 << Fixed::_raw))) {
  std::cout << "Int constructor called." << std::endl;
}

Fixed::Fixed(Fixed const &src) {
  std::cout << "Copy Constructor Called" << std::endl;
  *this = src;
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
  return this->_fixedValue;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits function called." << std::endl;
  this->_fixedValue = raw;
}

float Fixed::toFloat(void) const {
  return (float)this->_fixedValue / (float)(1 << Fixed::_raw);
}

int Fixed::toInt(void) const { return this->_fixedValue >> Fixed::_raw; }

std::ostream &operator<<(std::ostream &oStream, const Fixed &nbr) {
  oStream << nbr.toFloat();
  return oStream;
}

Fixed::~Fixed(void) { std::cout << "Destructor called." << std::endl; }
