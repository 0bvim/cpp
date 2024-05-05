#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("Cure") {
  std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(Cure const &rhs) {
  std::cout << "Cure copy constructor called" << std::endl;
  *this = rhs;
}

Cure &Cure::operator=(Cure const &rhs) {
  std::cout << "Cure assignment constructor called" << std::endl;
  if (this != &rhs) {
    this->_type = rhs._type;
  }
  return *this;
}

Cure::~Cure() { std::cout << "Cure destructor called" << std::endl; }

AMateria *Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
