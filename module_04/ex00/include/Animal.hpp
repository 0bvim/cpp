#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
protected:
  std::string _type;

public:
  Animal(void);
  virtual ~Animal(void);
  Animal(Animal const &rhs);
  virtual Animal &operator=(Animal const &rhs);

  virtual std::string getType(void) const;
	virtual void makeSound() const;
};

#endif // !ANIMAL_HPP
