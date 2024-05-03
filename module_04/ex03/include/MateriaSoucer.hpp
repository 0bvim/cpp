#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMaterialSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria* learnedMaterias[4];

public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(MateriaSource const &rhs);
	MateriaSource &operator=(MateriaSource const &rhs);
	
	void learnedMateria(AMateria* m);
	AMateria *createMateria(std::string const &type);
};

#endif // !MATERIASOURCE_HPP
