#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstdlib>
#include <string>

std::string trim(const std::string &str);

bool validateInput(const std::string &str);

bool isOp(char c);

bool doubleDigit(const std::string &str);

std::string trimInternSpaces(const std::string &str);

std::string trim(const std::string &str);

int performOperation(char op, int a, int b);

#endif // !UTILS_HPP
