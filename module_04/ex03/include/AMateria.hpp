#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria {
protected:
  std::string _type;

public:
  AMateria(void);
  AMateria(std::string const &type);
  virtual ~AMateria(void);
  AMateria(AMateria const &rhs);
  AMateria &operator=(AMateria const &rhs);

  std::string const &getType() const;
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};

#endif // !AMATERIA_HPP
