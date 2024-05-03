#include "Brain.hpp"
#include <cstddef>
#include <iostream>

Brain::Brain() { std::cout << "Brain Constructor called." << std::endl; }

Brain::~Brain() { std::cout << "Brain Destructor called." << std::endl; }

Brain::Brain(Brain const &rhs) {
  std::cout << "Brain copy constructor called." << std::endl;
  for (int i = 0; i < 100; ++i) {
    _ideas[i] = rhs._ideas[i];
  }
  *this = rhs;
}

Brain &Brain::operator=(Brain const &rhs) {
  std::cout << "Brain assignment constructor called." << std::endl;
  if (this != &rhs) {
    for (int i = 0; i < 100; ++i) {
      _ideas[i] = rhs._ideas[i];
    }
  }
  return *this;
}

void Brain::setIdea(std::string const idea, std::size_t index) {
  if (index < 100)
    _ideas[index] = idea;
  else
    std::cout << "Out of index" << std::endl;
}

std::string Brain::getIdea(std::size_t index) const {
  if (index < 100)
    return this->_ideas[index];
  else {
    std::cout << "Index out of range." << std::endl;
    return "Bad Idea";
  }
}
