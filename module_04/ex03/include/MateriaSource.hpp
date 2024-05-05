#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
  AMateria *_learnedMaterias[4];

public:
  MateriaSource();
  ~MateriaSource();
  MateriaSource(MateriaSource const &rhs);
  MateriaSource &operator=(MateriaSource const &rhs);

  void learnMateria(AMateria *m);
  AMateria *createMateria(std::string const &type);
};

#endif // !MATERIASOURCE_HPP
