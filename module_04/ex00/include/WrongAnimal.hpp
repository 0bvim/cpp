#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"

class wrongAnimal : public Animal {
public:
  wrongAnimal();
  ~wrongAnimal();
  wrongAnimal(wrongAnimal const &rhs);
  wrongAnimal &operator=(wrongAnimal const &rhs);
  void makeSound() const;
};

#endif // !WRONGANIMAL_HPP
