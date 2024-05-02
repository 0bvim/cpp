#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
  Ice();
  Ice(Ice const &rhs);
  Ice &operator=(Ice const &rhs);
  ~Ice();

  AMateria *clone() const;
  void use(ICharacter &target);
};

#endif // ICE_HPP
