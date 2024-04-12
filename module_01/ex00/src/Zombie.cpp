#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(void) {}

Zombie::~Zombie(void) {
  std::cout << "Destructor for " << this->_name << "called." << std::endl;
}

void Zombie::announce(void) {
  std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name) { this->_name = name; }

std::string Zombie::getName(void) { return this->_name; }
