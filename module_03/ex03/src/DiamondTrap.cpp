#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

#define SUFFIXNAME "_clap_name"

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap() {
  std::cout << "DiamondTrap Constructor Called." << std::endl;
  ClapTrap::setName(std::string("Foreign") + SUFFIXNAME);
  this->setName(std::string("Foreign") + SUFFIXNAME);
  ScavTrap::setEnergyPoint(50);
}

DiamondTrap::DiamondTrap(const std::string name)
    : ClapTrap(name + SUFFIXNAME), ScavTrap(name + SUFFIXNAME),
      FragTrap(name + SUFFIXNAME), _name(name + SUFFIXNAME) {
  std::cout << "DiamondTrap Constuctor Called." << std::endl;
  ScavTrap::setEnergyPoint(50);
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "DiamondTrap Destructor Called." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src)
    : ClapTrap(src), ScavTrap(src), FragTrap(src) {
  std::cout << "DiamondTrap copy constructor called." << std::endl;
  *this = src;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs) {
  std::cout << "DiamondTrap assignment constructor called." << std::endl;
  if (this != &rhs) {
    this->setName(rhs.getName());
    this->setHitPoints(rhs.getHitPoints());
    this->setEnergyPoint(rhs.getEnergypoint());
    this->setAttackDamage(rhs.getAttackDamage());
  }
  return *this;
}

void DiamondTrap::attack(const std::string &target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
  std::cout << "My name is: " << this->getName()
            << " and ClapTrap name is: " << ClapTrap::getName() << std::endl;
}
