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

Zombie* newZombie(std::string name);

void randomChump(std::string name);

#endif // !ZOMBIE_HPP
