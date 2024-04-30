#include "WrongAnimal.hpp"
#include <iostream>

wrongAnimal::wrongAnimal() {
  _type = "wrongAnimal";
  std::cout << "wrongAnimal constructor called." << std::endl;
}

wrongAnimal::~wrongAnimal() { std::cout << "wrongAnimal destructor called." << std::endl; }

wrongAnimal::wrongAnimal(wrongAnimal const &rhs) : Animal(rhs) {
  std::cout << "wrongAnimal copy constructor called." << std::endl;
  *this = rhs;
}

void wrongAnimal::makeSound() const {
	std::cout << "Wrong Animal Sound" << std::endl;
}
