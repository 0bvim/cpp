#include "Brain.hpp"
#include <iostream>

Brain::Brain() { std::cout << "Brain Constructor called." << std::endl; }

Brain::~Brain() { std::cout << "Brain Destructor called." << std::endl; }

Brain::Brain(Brain const &rhs) {
  std::cout << "Brain copy constructor called." << std::endl;
  for (int i = 0; i < 100; ++i) {
    ideas[i] = rhs.ideas[i];
  }
  *this = rhs;
}

Brain &Brain::operator=(Brain const &rhs) {
  std::cout << "Brain assignment constructor called." << std::endl;
  if (this != &rhs) {
    for (int i = 0; i < 100; ++i) {
      ideas[i] = rhs.ideas[i];
    }
  }
  return *this;
}
