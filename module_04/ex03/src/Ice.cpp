#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("Ice") {
  std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(Ice const &rhs) {
  std::cout << "Ice copy constructor called" << std::endl;
  *this = rhs;
}

Ice &Ice::operator=(Ice const &rhs) {
  std::cout << "Ice assignment constructor called" << std::endl;
  if (this != &rhs) {
    this->_type = rhs._type;
  }
  return *this;
}

Ice::~Ice() { std::cout << "Ice destructor called" << std::endl; }

AMateria *Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
