#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
protected:
  std::string _type;

public:
  Animal(void);
  ~Animal(void);
  Animal(Animal const &rhs);
  Animal &operator=(Animal const &rhs);

  void setType(const std::string type);
  std::string getType(void) const;
};

#endif // !ANIMAL_HPP
