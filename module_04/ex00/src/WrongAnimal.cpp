#include "WrongAnimal.hpp"
#include <iostream>

wrongAnimal::wrongAnimal() {
  _type = "wrongAnimal";
  std::cout << "Wrong Animal constructor called." << std::endl;
}

wrongAnimal::~wrongAnimal() {
  std::cout << "Wrong Animal destructor called." << std::endl;
}

wrongAnimal::wrongAnimal(wrongAnimal const &rhs) : Animal(rhs) {
  std::cout << "Wrong Animal copy constructor called." << std::endl;
  *this = rhs;
}

wrongAnimal &wrongAnimal::operator=(wrongAnimal const &rhs) {
  std::cout << "Wrong Animal assignment operator called." << std::endl;
  if (this != &rhs) {
    this->_type = rhs._type;
  }
  return *this;
}

void wrongAnimal::makeSound() const {
  std::cout << "Wrong Animal Sound" << std::endl;
}
