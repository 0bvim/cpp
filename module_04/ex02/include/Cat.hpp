#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
private:
  Brain *brain;

public:
  Cat();
  ~Cat();
  Cat(Cat const &rhs);
  Cat &operator=(Cat const &rhs);
  void makeSound() const;
};

#endif // !CAT_HPP
