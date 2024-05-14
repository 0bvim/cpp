#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <algorithm>
#include <exception>
#include "Defines.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
			throw std::runtime_error("Value not found in container");
		}
	return it;
}

#endif // EASYFIND_TPP
