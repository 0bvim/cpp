#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
  _type = "Dog";
  std::cout << "Dog constructor called." << std::endl;
  _brain = new Brain();
}

Dog::~Dog() {
  std::cout << "Dog destructor called." << std::endl;
  delete _brain;
}

Dog::Dog(Dog const &rhs) : AAnimal(rhs) {
  std::cout << "Dog copy constructor called." << std::endl;
  *this = rhs;
	_brain = new Brain();
}

Dog &Dog::operator=(Dog const &rhs) {
  std::cout << "Dog assignment operator called." << std::endl;
  if (this != &rhs) {
    this->_type = rhs._type;
    *_brain = *(rhs._brain);
  }
  return *this;
}

void Dog::makeSound() const { std::cout << "Woof" << std::endl; }

Brain *Dog::getBrain(void) const {
	return _brain;
}
