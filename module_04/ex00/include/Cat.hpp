#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
  Cat();
  ~Cat();
  Cat(Cat const &rhs);
  Cat &operator=(Cat const &rhs);
  void makeSound() const;
};

#endif // !CAT_HPP
