#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"
#include <cstddef>

template <typename T> Array<T>::Array() : _data(new T[0]()), _size(0) {}

template <typename T>
Array<T>::Array(const unsigned int &n) : _data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array &rhs) : _data(new T[rhs._size]), _size(rhs._size) {
  for (std::size_t i = 0; i < _size; ++i) {
    _data[i] = rhs._data[i];
  }
}

template <typename T> Array<T>::~Array() { delete[] _data; }

template <typename T> Array<T> &Array<T>::operator=(const Array &rhs) {
  if (this != &rhs) {
    delete[] _data;
    _size = rhs._size;
    _data = new T[_size];
    for (std::size_t i = 0; i < _size; ++i) {
      _data[i] = rhs._data[i];
    }
  }
  return *this;
}

template <typename T> unsigned int Array<T>::size() const {
  return this->_size;
}

template <typename T> T &Array<T>::operator[](const unsigned int &index) const {
  if (index >= this->_size) {
    throw std::out_of_range("Index out of range");
  }
  return this->_data[index];
}

template <typename T> T &Array<T>::operator[](const unsigned int &index) {
  if (index >= this->_size) {
    throw std::out_of_range("Index out of range");
  }
  return this->_data[index];
}

template <typename T>
std::ostream &operator<<(std::ostream &lhs, const Array<T> &rhs) {
  const unsigned int n = rhs.size();

  lhs << "ARRAY { ";

  for (unsigned int i = 0; i < n; i++) {
    lhs << rhs[i];
    if (i != n - 1) {
      lhs << ", ";
    }
  }
  lhs << " }";
  return lhs;
}

#endif // ARRAY_TPP
