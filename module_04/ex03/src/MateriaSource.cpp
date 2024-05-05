#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; ++i) {
    _learnedMaterias[i] = NULL;
  }
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; ++i) {
    delete _learnedMaterias[i];
  }
}

MateriaSource::MateriaSource(MateriaSource const &rhs) { *this = rhs; }

MateriaSource &MateriaSource::operator=(MateriaSource const &rhs) {
  if (this != &rhs) {
    for (int i = 0; i < 4; ++i) {
      if (rhs._learnedMaterias[i]) {
        this->_learnedMaterias[i] = rhs._learnedMaterias[i]->clone();
      } else {
        this->_learnedMaterias[i] = NULL;
      }
    }
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
  for (int i = 0; i < 4; ++i) {
    if (_learnedMaterias[i] == NULL) {
      _learnedMaterias[i] = m;
      break;
    }
  }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < 4; ++i) {
    if (_learnedMaterias[i] != NULL && _learnedMaterias[i]->getType() == type)
      return _learnedMaterias[i]->clone();
  }
  return 0;
}
