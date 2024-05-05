#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("Ice") {}

Ice::Ice(Ice const &rhs) : AMateria(rhs) { *this = rhs; }

Ice &Ice::operator=(Ice const &rhs) {
  if (this != &rhs) {
    this->_type = rhs._type;
  }
  return *this;
}

Ice::~Ice() {}

AMateria *Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter &target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
