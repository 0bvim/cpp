#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
  _type = "Dog";
  std::cout << "Dog constructor called." << std::endl;
}

Dog::~Dog() { std::cout << "Dog destructor called." << std::endl; }

Dog::Dog(Dog const &rhs) : Animal(rhs) {
  std::cout << "Dog copy constructor called." << std::endl;
  *this = rhs;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}
