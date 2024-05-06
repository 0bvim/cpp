#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &rhs) : AMateria(rhs) { *this = rhs; }

Cure &Cure::operator=(Cure const &rhs) {
  if (this != &rhs) {
    this->_type = rhs._type;
  }
  return *this;
}

Cure::~Cure() {}

AMateria *Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
