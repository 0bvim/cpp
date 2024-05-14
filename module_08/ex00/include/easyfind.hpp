#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iterator>

template <typename  T>
typename T::iterator easyfind(T& container, int value);

#include "../src/easyfind.tpp"

#endif // !EASYFIND_HPP
