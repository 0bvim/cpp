#include "PmergeMe.hpp"
#include <cstdlib>
#include <list>
#include <vector>

Ford::Ford() {}

Ford::~Ford() {}

Ford::Ford(const std::vector<int> &nb, const std::list<int> &lnb)
    : _vseq(nb), _lseq(lnb) {}

Ford::Ford(const Ford &rhs) { *this = rhs; }

Ford &Ford::operator=(const Ford &rhs) {
  if (this != &rhs) {
    this->_vseq = rhs._vseq;
    this->_lseq = rhs._lseq;
  }
  return *this;
}

std::vector<int> Ford::getVector(void) const { return _vseq; }

std::list<int> Ford::getList(void) const { return _lseq; }
