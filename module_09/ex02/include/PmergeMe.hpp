#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
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

#endif // !PMERGEME_HPP
