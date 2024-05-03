#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void) : _type("none") {
  std::cout << "AMateria constructor called." << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type) {
  std::cout << "AMateria type constructor called." << std::endl;
}

AMateria::~AMateria(void) {
  std::cout << "AMateria destructor called." << std::endl;
}

AMateria::AMateria(AMateria const &rhs) {
  std::cout << "AMateria copy contructor called." << std::endl;
  *this = rhs;
}

AMateria &AMateria::operator=(AMateria const &rhs) {
  std::cout << "AMateria assignment contructor called." << std::endl;
  if (this != &rhs) {
    this->_type = rhs._type;
  }
  return *this;
}

std::string const &AMateria::getType() const { return _type; }

void AMateria::use(ICharacter &target) {
  std::cout << "Nothing in use yet for" << target.getType() << std::endl;
}
