#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap(void) { std::cout << "Constructor Called." << std::endl; }

ClapTrap::ClapTrap(std::string name)
    : _name(name), _energyPoints(10), _hitPoints(10), _attackDamage(0) {
  std::cout << "Constructor Called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	std::cout << "Copy Constructor Called" << std::endl;
	*this = src;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
  std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_energyPoints = rhs._energyPoints;
		this->_hitPoints = rhs._hitPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void) { std::cout << "Destructor Called." << std::endl; }

