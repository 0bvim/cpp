#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {

public:
  Zombie(void);
  ~Zombie(void);

  void announce(void);
  void setName(const std::string &name);
  std::string getName(void);

private:
  std::string _name;
};

#endif // !ZOMBIE_HPP
