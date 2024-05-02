#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void) : _type("Generic AAnimal") {
  std::cout << "Generic Aanimal constructor called." << std::endl;
}

AAnimal::~AAnimal(void) { std::cout << "AAnimal destructor called." << std::endl; }

AAnimal::AAnimal(AAnimal const &rhs) {
  std::cout << "AAnimal copy constructor called." << std::endl;
  *this = rhs;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs) {
  std::cout << "AAnimal assignment operator called." << std::endl;
  if (this != &rhs) {
    this->_type = rhs._type;
  }
  return *this;
}

std::string AAnimal::getType(void) const { return this->_type; }

void AAnimal::makeSound() const {
  std::cout << "Generic AAnimal Sound" << std::endl;
}
