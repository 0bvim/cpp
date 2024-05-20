#include "utils.h"
#include <cctype>
#include <iostream>
#include <ostream>
#include <set>
#include <stdexcept>
#include <string>

std::string trim(const std::string &str) {
  std::string::const_iterator start = str.begin();
  while (start != str.end() && std::isspace(*start)) {
    start++;
  }

  std::string::const_reverse_iterator end = str.rbegin();
  while (end.base() != start && std::isspace(*end)) {
    end++;
  }

  return std::string(start, end.base());
}

std::string trimInternSpaces(const std::string &str) {
  std::string newStr = "";

  std::string::const_iterator start = str.begin();
  while (start != str.end() && std::isspace(*start)) {
    start++;
  }

  std::string::const_reverse_iterator end = str.rbegin();
  while (end.base() != start && std::isspace(*end)) {
    end++;
  }

  for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
    if (!::isspace(*it)) {
      newStr += *it;
    }
  }

  return newStr;
}

template <typename Container>
Container validateAndProcessInput(char **input, const size_t &elements) {
  Container numbers;
  std::set<typename Container::value_type>
      seenNumbers;

  for (size_t i = 1; i < elements; ++i) {
    int num = std::atoi(input[i]);
    if (num <= 0) {
      throw std::invalid_argument("Number must be positive.");
    }
    if (!seenNumbers.insert(num).second) {
      std::cout << "Duplicate number detected: " << num << std::endl;
      throw std::invalid_argument("Duplicate number detected.");
    }
    numbers.push_back(num); // Use push_back for both vector and list in C++98
  }

  return numbers;
}
