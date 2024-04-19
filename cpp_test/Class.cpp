#include "Class.hpp"
#include <iostream>

Sample::Sample(void) : _foo(0) {
  std::cout << "Default Constructor Called" << std::endl;
  return;
}

Sample::Sample(int const n) : _foo(n) {
  std::cout << "Parametric Constructor Called" << std::endl;
  return;
}

Sample::Sample(Sample const &src) {
  std::cout << "Copy Constructor Called" << std::endl;
	*this = src;
  return;
}

Sample &Sample::operator=(Sample const &rhs) {
  std::cout << "Assignment operator called" << std::endl;
  if (this != &rhs) {
    this->_foo = rhs.getFoo();
  }
  return *this;
}

Sample::~Sample(void) {
  std::cout << "Destructor Called" << std::endl;
  return;
}

// const is to how try access have a 'read-only mode'
int Sample::getFoo(void) const { return this->_foo; }

void Sample::setFoo(int v) {
  if (v >= 0)
    this->_foo = v;
  return;
}
