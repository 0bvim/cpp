#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <stdexcept>

Span::Span(unsigned int N) : _maxSize(N) {}

Span::~Span() {}

Span::Span(const Span &rhs) : _numbers(rhs._numbers), _maxSize(rhs._maxSize) {}

Span &Span::operator=(const Span &rhs) {
  if (this != &rhs) {
    _numbers = rhs._numbers;
    _maxSize = rhs._maxSize;
  }
  return *this;
}

void Span::addNumber(int number) {
  if (_numbers.size() >= _maxSize)
    throw std::overflow_error("Cannot add more numbers. Span is full.");
  _numbers.push_back(number);
}

int Span::shortestSpan() const {
  if (_numbers.size() < 2)
    throw std::logic_error("Not enough numbers to find a span.");
  std::vector<int> sorted(_numbers);
  std::sort(sorted.begin(), sorted.end());
  int minSpan = std::numeric_limits<int>::max();
  for (size_t i = 1; i < sorted.size(); ++i) {
    int span = sorted[i] - sorted[i - 1];
    if (span < minSpan) {
      minSpan = span;
    }
  }
  return std::abs(minSpan);
}

int Span::longestSpan() const {
  if (_numbers.size() < 2)
    throw std::logic_error("Not enough numbers to find a span.");

  int minNum = *std::min_element(_numbers.begin(), _numbers.end());
  int maxNum = *std::max_element(_numbers.begin(), _numbers.end());
  return std::abs(maxNum - minNum);
}
