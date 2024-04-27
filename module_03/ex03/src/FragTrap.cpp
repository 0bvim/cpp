#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap() {
  std::cout << "FragTrap Constructor Called." << std::endl;
  this->setHitPoints(100);
  this->setEnergyPoint(100);
  this->setAttackDamage(30);
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
  std::cout << "FragTrap Constuctor Called." << std::endl;
  this->setHitPoints(100);
  this->setEnergyPoint(100);
  this->setAttackDamage(30);
}

FragTrap::~FragTrap(void) {
  std::cout << "FragTrap Destructor Called." << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {
  std::cout << "FragTrap copy constructor called." << std::endl;
  *this = src;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
  std::cout << "FragTrap assignment constructor called." << std::endl;
  if (this != &rhs) {
    this->setName(rhs.getName());
    this->setHitPoints(rhs.getHitPoints());
    this->setEnergyPoint(rhs.getEnergypoint());
    this->setAttackDamage(rhs.getAttackDamage());
  }
  return *this;
}

// Member functions
void FragTrap::attack(const std::string &target) {
  if (!getEnergypoint()) {
    std::cout << "FragTrap " << getName() << " is out of energy." << std::endl;
    return;
  }
  if (target.empty()) {
    messages(ClapTrap::EMPTY_ATK);
    return;
  }
  std::cout << "FragTrap " << getName() << " attacks " << target << ", causing "
            << getAttackDamage() << " points of damage!" << std::endl;
  setEnergyPoint(this->getEnergypoint() - 1);
}

void FragTrap::highFivesGuys(void) {
  std::cout << "High five request has been accepted succefully!" << std::endl;
}
