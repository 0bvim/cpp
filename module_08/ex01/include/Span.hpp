#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
private:
  std::vector<int> _numbers;
  unsigned int _maxSize;

public:
  Span();
  Span(unsigned int N);
  Span(Span const &rhs);
  Span &operator=(Span const &rhs);
  ~Span();
	
  void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;
};
#endif // SPAN_HPP
