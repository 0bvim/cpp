#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstdlib>
#include <string>

bool isInteger(const std::string &str);

bool leapYear(int year);

bool isValidDate(int year, int month, int day);

bool validateDate(const std::string &date);

bool validatePrice(double value);

std::string trim(const std::string &str);

#endif // !UTILS_HPP
