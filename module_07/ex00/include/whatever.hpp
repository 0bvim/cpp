#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T> void swap(T &first, T &second) {
  T holder = first;
  first = second;
  second = holder;
}

template <typename T> T min(T const &first, T const &second) {
  return first < second ? first : second;
}

template <typename T> T max(T const &first, T const &second) {
  return first > second ? first : second;
}

#endif // WHATEVER_HPP
