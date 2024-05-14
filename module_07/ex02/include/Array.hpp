#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <ostream>

template <typename T> class Array {
private:
  T *_data;
  size_t _size;

public:
  Array();
  Array(const unsigned int &n);
  Array(const Array &rhs);
  ~Array();

  Array &operator=(const Array &other);

  unsigned int size() const;

  T const &operator[](const unsigned int &index) const;
  T &operator[](const unsigned int &index);
};

template <typename T>
std::ostream &operator<<(std::ostream &lhs, const Array<T> &rhs);

#include "../src/Array.tpp"

#endif // ARRAY_HPP
