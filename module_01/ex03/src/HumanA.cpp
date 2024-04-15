#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon), _name(name)  {}

HumanA::~HumanA() {}

const std::string &HumanA::getName() { return _name; }

void HumanA::setName(const std::string &name) { _name = name; }

void HumanA::setWeapon(Weapon weapon) { _weapon = weapon; }

const std::string &HumanA::getWeapon() { return _weapon.getType(); }

void HumanA::attack() {
  std::cout << this->getName() + " attacks with their " << getWeapon()
            << std::endl;
}
