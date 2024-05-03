#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <cstddef>
#include <string>

class Brain {
private:
  std::string _ideas[100];

public:
  Brain();
  ~Brain();
  Brain(Brain const &rhs);
  Brain &operator=(Brain const &rhs);

	void setIdea(std::string const idea, std::size_t index);
	std::string getIdea(std::size_t index) const;
};

#endif // !BRAIN_HPP
