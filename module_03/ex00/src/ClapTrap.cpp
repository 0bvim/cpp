#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap(void) { std::cout << "Constructor Called." << std::endl; }

ClapTrap::ClapTrap(const std::string name)
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

void ClapTrap::setName(const std::string name) { this->_name = name; }
void ClapTrap::setHitPoints(unsigned int hp) { this->_hitPoints = hp; }
void ClapTrap::setEnergyPoint(unsigned int ep) { this->_energyPoints = ep; }
void ClapTrap::setAttackDamage(unsigned int atk) { this->_attackDamage = atk; }
std::string ClapTrap::getName(void) const { return _name; }
unsigned int ClapTrap::getHitPoints(void) const { return _hitPoints; }
unsigned int ClapTrap::getEnergypoint(void) const { return _energyPoints; }
unsigned int ClapTrap::getAttackDamage(void) const { return _attackDamage; }

void ClapTrap::attack(const std::string &target) {
  if (!getEnergypoint()) {
    std::cout << "ClapTrap " << getName() << " is out of energy." << std::endl;
    return;
  }
  std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing "
            << getAttackDamage() << " points of damage!" << std::endl;
	_energyPoints -= 1;
}
