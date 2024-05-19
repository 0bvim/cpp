#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>

class Ford {
private:
  std::vector<int> _seq;
  Ford();

public:
  Ford(const std::string &input);
  ~Ford();
  Ford(const Ford &rhs);
  Ford &operator=(const Ford &rhs);

	std::vector<int> getVector(void);
};

#endif // !PMERGEME_HPP
