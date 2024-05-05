#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Character::Character(void) : _name("none") {
  for (int i = 0; i < 4; ++i) {
    _inventory[i] = NULL;
  }
}

Character::Character(std::string const &name) : _name(name) {
  for (int i = 0; i < 4; ++i) {
    _inventory[i] = NULL;
  }
}

Character::Character(Character const &rhs) {
  *this = rhs;
}

Character::~Character(void) {
  for (int i = 0; i < 4; ++i) {
    delete _inventory[i];
  }
}

Character &Character::operator=(Character const &rhs) {
  if (this != &rhs) {
    this->_name = rhs._name;
    for (int i = 0; i < 4; ++i) {
      if (rhs._inventory[i]) {
        this->_inventory[i] = rhs._inventory[i]->clone();
      } else {
        this->_inventory[i] = NULL;
      }
    }
  }
  return *this;
}

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria *m) {
  for (int i = 0; i < 4; ++i) {
    if (_inventory[i] == NULL) {
      _inventory[i] = m;
      break;
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx < 4) {
    _inventory[idx] = NULL;
  }
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= 0 && idx < 4 && _inventory[idx] != NULL) {
    _inventory[idx]->use(target);
  }
}
