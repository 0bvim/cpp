#include "Span.hpp"
#include <algorithm>
#include <exception>
#include <limits>

Span::Span() : _numbers(0), _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::~Span() {}

Span::Span(const Span &rhs) : _numbers(rhs._numbers), _maxSize(rhs._maxSize) {}

Span &Span::operator(const Span &rhs) {
	if (this != &rhs) {
		_numbers = rhs._numbers;
		_maxSize = rhs._maxSize;
	}
	return *this;
}

void Span::addNumber(int number) {
	if (_numbers.size() >=  _maxSize)
		throw std::overflow_error("Cannot add more numbers. Span is full.");
	_numbers.push_back(number);
}

int Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span.");
	std::std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());
	int minSpan = std::numeric_limits<int>::max();
	
}