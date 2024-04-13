#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB() : _weapon(__null), _name(__null) {}

HumanB::HumanB(const std::string &name) : _weapon(__null), _name(name) {}

HumanB::~HumanB() {}

const std::string &HumanB::getName() { return _name; }

void HumanB::setName(const std::string &name) { _name = name; }

void HumanB::setWeapon(Weapon &weapon) { _weapon = &weapon; }

const std::string &HumanB::getWeapon() { return _weapon->getType(); }

void HumanB::attack() const {
  std::cout << this->_name + " attacks with their "
            << (_weapon != NULL ? _weapon->getType() : "hand")
            << std::endl;
}
