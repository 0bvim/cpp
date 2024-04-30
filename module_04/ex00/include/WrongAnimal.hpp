#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"

class wrongAnimal : public Animal {
public:
  wrongAnimal();
  ~wrongAnimal();
  wrongAnimal &operator=(const wrongAnimal &rhs);
  void makeSound() const;
};

#endif // !WRONGANIMAL_HPP
