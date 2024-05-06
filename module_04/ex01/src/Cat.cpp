#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
  _type = "Cat";
  std::cout << "Cat constructor called." << std::endl;
  brain = new Brain();
}

Cat::~Cat() {
  std::cout << "Cat destructor called." << std::endl;
  delete brain;
}

Cat::Cat(Cat const &rhs) : Animal(rhs) {
  std::cout << "Cat copy constructor called." << std::endl;
  this->brain = new Brain();
  *this = rhs;
}

Cat &Cat::operator=(Cat const &rhs) {
  std::cout << "Cat assignment operator called." << std::endl;
  if (this != &rhs) {
    this->_type = rhs._type;
    *brain = *(rhs.brain);
  }
  return *this;
}

void Cat::makeSound() const { std::cout << "Meow" << std::endl; }
