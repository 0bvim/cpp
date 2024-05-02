#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
  _type = "Dog";
  std::cout << "Dog constructor called." << std::endl;
  brain = new Brain();
}

Dog::~Dog() {
  std::cout << "Dog destructor called." << std::endl;
  delete brain;
}

Dog::Dog(Dog const &rhs) : Animal(rhs) {
  std::cout << "Dog copy constructor called." << std::endl;
  *this = rhs;
}

Dog &Dog::operator=(Dog const &rhs) {
  std::cout << "Dog assignment operator called." << std::endl;
  if (this != &rhs) {
    this->_type = rhs._type;
  }
  return *this;
}

void Dog::makeSound() const { std::cout << "Woof" << std::endl; }
