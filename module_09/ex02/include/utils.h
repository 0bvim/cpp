#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstdlib>
#include <string>

std::string trim(const std::string &str);

std::string trimInternSpaces(const std::string &str);

template <typename Container>
Container validateAndProcessInput(char **input, const size_t &elements);

#endif // !UTILS_HPP
