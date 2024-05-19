#include "utils.h"
#include <cctype>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

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

bool isOp(char c) { return c == '+' || c == '-' || c == '/' || c == '*'; }

bool doubleDigit(const std::string &str) {
  std::string noSpace = trim(str);
  for (std::string::const_iterator it = noSpace.begin(); it != noSpace.end();
       ++it) {
    while (::isspace(*it)) {
      ++it;
    }
    if (::isdigit(*it) && ::isdigit(*(it + 1))) {
      return true;
    } else if (isOp(*it) && isOp(*(it + 1)))
      return true;
  }
  return false;
}

int performOperation(char op, int a, int b) {

  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    if (b == 0) {
      throw std::runtime_error("Division by zero");
    }
    return a / b;
  default:
    throw std::invalid_argument("Invalid operator");
  }
}

bool hasDuplicates(std::vector<int> &numbers) {
  for (unsigned int i = 0; i < numbers.size(); ++i) {
    for (unsigned int j = i + 1; j < numbers.size(); ++j) {
      if (numbers[i] == numbers[j]) {
        std::cout << "Duplicate number detected: " << numbers[i] << std::endl;
        return true;
      }
    }
  }
  return false;
}

std::vector<int> inputValidation(char **input, const size_t &elements) {
  std::vector<int> numbers(elements - 1);
  for (size_t i = 1; i < elements; ++i) {
    numbers[i - 1] = atoi(input[i]);
    if (numbers[i - 1] <= 0) {
      throw std::invalid_argument("Number must be positive.");
    }
  }
  return numbers;
}
