#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("Generic Animal") {
  std::cout << "Generic animal constructor called." << std::endl;
}

Animal::~Animal(void) { std::cout << "Animal destructor called." << std::endl; }

Animal::Animal(Animal const &rhs) {
  std::cout << "Animal copy constructor called." << std::endl;
  *this = rhs;
}

Animal &Animal::operator=(Animal const &rhs) {
  std::cout << "Animal assignment operator called." << std::endl;
  if (this != &rhs) {
    this->_type = rhs._type;
  }
  return *this;
}

std::string Animal::getType(void) const { return this->_type; }

void Animal::makeSound() const {
	std::cout << "Generic Animal Sound" << std::endl;
}
