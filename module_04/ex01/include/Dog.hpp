#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
  Brain *brain;

public:
  Dog();
  ~Dog();
  Dog(Dog const &rhs);
  Dog &operator=(Dog const &rhs);
  void makeSound() const;
};

#endif // !DOG_HPP
