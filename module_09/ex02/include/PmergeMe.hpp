#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdlib>
#include <iostream>
#include <list>
#include <ostream>
#include <set>
#include <stdexcept>
#include <vector>

class Ford {
private:
  std::vector<int> _vseq;
  std::list<int> _lseq;

public:
  Ford();
  Ford(const std::vector<int> &nb, const std::list<int> &lnb);
  ~Ford();
  Ford(const Ford &rhs);
  Ford &operator=(const Ford &rhs);

  std::vector<int> getVector(void) const;
  std::list<int> getList(void) const;
};

template <typename Container>
Container validateAndProcessInput(char **input, int &elements) {
  Container numbers;
  std::set<typename Container::value_type> seenNumbers;

  for (int i = 1; i < elements; ++i) {
    int num = std::atoi(input[i]);
    if (num <= 0) {
      throw std::invalid_argument("Number must be positive.");
    }
    if (!seenNumbers.insert(num).second) {
      std::cout << "Duplicate number detected: " << num << std::endl;
      throw std::invalid_argument("Duplicate number detected.");
    }
    numbers.push_back(num);
  }
  return numbers;
}

template <typename Container>
void printSequence(const Container& seq) {
    typename Container::const_iterator it;
    for (it = seq.begin(); it != seq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

#endif // !PMERGEME_HPP
