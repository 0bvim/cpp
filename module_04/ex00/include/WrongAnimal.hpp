#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class wrongAnimal {
protected:
  std::string _type;

public:
  wrongAnimal();
  ~wrongAnimal();
  wrongAnimal(wrongAnimal const &rhs);
  wrongAnimal &operator=(wrongAnimal const &rhs);

  std::string getType(void) const;
  void makeSound() const;
};

#endif // !WRONGANIMAL_HPP
