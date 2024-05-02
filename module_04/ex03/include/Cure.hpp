#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
  Cure();
  Cure(Cure const &rhs);
  Cure &operator=(Cure const &rhs);
  ~Cure();

  AMateria *clone() const;
  void use(ICharacter &target);
};

#endif // !CURE_HPP
