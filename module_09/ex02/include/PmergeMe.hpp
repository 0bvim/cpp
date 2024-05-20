#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "Defines.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <ostream>
#include <set>
#include <stdexcept>
#include <vector>

extern bool printAfter;

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

template <typename Iterator>
void merge(Iterator first, Iterator mid, Iterator last) {
  typedef typename std::iterator_traits<Iterator>::value_type T;
  std::vector<T> sortedSeq;
  sortedSeq.reserve(std::distance(first, last));

  Iterator it1 = first;
  Iterator it2 = mid;
  while (it1 != mid && it2 != last) {
    if (*it1 < *it2) {
      sortedSeq.push_back(*it1);
      ++it1;
    } else {
      sortedSeq.push_back(*it2);
      ++it2;
    }
  }
  while (it1 != mid) {
    sortedSeq.push_back(*it1);
    ++it1;
  }
  while (it2 != last) {
    sortedSeq.push_back(*it2);
    ++it2;
  }

  std::copy(sortedSeq.begin(), sortedSeq.end(), first);
}

template <typename Iterator>
void mergeInsertSortRecursively(Iterator first, Iterator last) {
  if (std::distance(first, last) <= 1)
    return;

  Iterator mid = first;
  std::advance(mid, std::distance(first, last) / 2);
  mergeInsertSortRecursively(first, mid);
  mergeInsertSortRecursively(mid, last);

  merge(first, mid, last);
}

template <typename Container> void mergeInsertSort(Container &seq) {
  mergeInsertSortRecursively(seq.begin(), seq.end());
}

template <typename Container>
Container validateAndProcessInput(char **input, int &elements) {
  Container numbers;
  std::set<typename Container::value_type> seenNumbers;

  for (int i = 1; i < elements; ++i) {
    int num = std::atoi(input[i]);
    if (num <= 0) {
      throw std::invalid_argument(
          "Number must be positive or not double signal.");
    }
    if (!seenNumbers.insert(num).second) {
      std::cout << "Duplicate number detected: " << num << std::endl;
      throw std::invalid_argument("Duplicate number detected.");
    }
    numbers.push_back(num);
  }
  return numbers;
}

template <typename Container> void printSequence(const Container &seq) {
  typename Container::const_iterator it;
  for (it = seq.begin(); it != seq.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

template <typename Container>
void displayTime(Container &seq, const std::string &containerName) {
  clock_t start = clock();
  mergeInsertSort(seq);
  clock_t end = clock();
  if (!printAfter) {
    std::cout << MAGENTA("after: ");
    printSequence(seq);
    NL;
  }
  double timeInSeconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  std::cout << "Time to process a range of " << YELLOW(seq.size())
            << YELLOW(" elements with") << BLUE(" std::" << containerName)
            << ": " << (timeInSeconds * 1000.0) << " us" << std::endl;
}

#endif // !PMERGEME_HPP
