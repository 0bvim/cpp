#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : _hitPoint(100), _energyPoint(50), _atkDmg(20) {
  std::cout << "ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
    : _name(name), _hitPoint(100), _energyPoint(50), _atkDmg(20) {
  std::cout << "ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) {
  std::cout << "ScavTrap copy constructor called." << std::endl;
  *this = src;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
  std::cout << "ScavTrap assignment constructor called." << std::endl;
  if (this != &rhs) {
    this->_name = rhs._name;
    this->_hitPoint = rhs._hitPoint;
    this->_energyPoint = rhs._energyPoint;
    this->_atkDmg = rhs._atkDmg;
  }
  return *this;
}
