#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include "Brain.hpp"

class AAnimal {
protected:
  std::string _type;

public:
  AAnimal(void);
  virtual ~AAnimal(void);
  AAnimal(AAnimal const &rhs);
  AAnimal &operator=(AAnimal const &rhs);

  virtual std::string getType(void) const;
	virtual void makeSound() const = 0;
	virtual Brain *getBrain(void) const = 0;
};

#endif // !AANIMAL_HPP
