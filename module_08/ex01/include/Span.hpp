#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
private:
  std::vector<int> numbers;
  unsigned int maxSize;

public:
  Span();
  Span(unsigned int N);
  Span(Span const &rhs);
  Span &operator=(Span const &rhs);
  ~Span();
	
	int shortestSpan() const;
	int longestSpan() const;
};
#endif // SPAN_HPP
