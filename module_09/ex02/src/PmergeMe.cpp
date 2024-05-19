#include "PmergeMe.hpp"

Ford::Ford() {}

Ford::~Ford() {}

Ford::Ford(const Ford &rhs) { *this = rhs; }

Ford &Ford::operator=(const Ford &rhs) {
  if (this != &rhs) {
    this->_seq = rhs._seq;
  }
  return *this;
}
