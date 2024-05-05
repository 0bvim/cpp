#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(void) : _type("none") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::~AMateria(void) {}

AMateria::AMateria(AMateria const &rhs) { *this = rhs; }

AMateria &AMateria::operator=(AMateria const &rhs) {
  if (this != &rhs) {
    this->_type = rhs._type;
  }
  return *this;
}

std::string const &AMateria::getType() const { return _type; }

void AMateria::use(ICharacter &target) {
  std::cout << "Nothing in use yet for" << target.getName() << std::endl;
}
