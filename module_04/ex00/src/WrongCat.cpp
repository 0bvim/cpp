#include "WrongCat.hpp"
#include <iostream>

wrongCat::wrongCat() {
  _type = "wrongCat";
  std::cout << "wrongCat constructor called." << std::endl;
}

wrongCat::~wrongCat() {
  std::cout << "wrongCat destructor called." << std::endl;
}

wrongCat::wrongCat(wrongCat const &rhs) : wrongAnimal(rhs) {
  std::cout << "wrongCat copy constructor called." << std::endl;
  *this = rhs;
}

wrongCat &wrongCat::operator=(wrongCat const &rhs) {
  std::cout << "wrongCat assignment operator called." << std::endl;
  if (this != &rhs) {
    this->_type = rhs._type;
  }
  return *this;
}

void wrongCat::makeSound() const { std::cout << "Meow" << std::endl; }
