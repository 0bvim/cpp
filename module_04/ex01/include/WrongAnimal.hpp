#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class wrongAnimal {
protected:
  std::string _type;

public:
  wrongAnimal();
  virtual ~wrongAnimal();
  wrongAnimal(wrongAnimal const &rhs);
  wrongAnimal &operator=(wrongAnimal const &rhs);

  virtual std::string getType(void) const;
  virtual void makeSound() const;
};

#endif // !WRONGANIMAL_HPP
