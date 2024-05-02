#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
private:
  std::string ideas[100];

public:
	Brain();
	virtual ~Brain();
	Brain(Brain const &rhs);
	Brain &operator=(Brain const &rhs);

};

#endif // !BRAIN_HPP
