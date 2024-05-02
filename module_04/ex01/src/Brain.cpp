#include "Brain.hpp"
#include <cstring>
#include <iostream>

Brain::Brain() { std::cout << "Brain Constructor called." << std::endl; }

Brain::~Brain() { std::cout << "Brain Destructor called." << std::endl; }

Brain::Brain(Brain const &rhs) {
  std::cout << "Brain copy constructor called." << std::endl;
  std::memcpy(this->ideas, rhs.ideas, sizeof(ideas));
  *this = rhs;
}

Brain &Brain::operator=(Brain const &rhs) {
  std::cout << "Brain assignment constructor called." << std::endl;
  if (this != &rhs) {
    std::memcpy(this->ideas, rhs.ideas, sizeof(ideas));
  }
  return *this;
}
