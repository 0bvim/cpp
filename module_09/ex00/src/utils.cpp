#include "utils.h"
#include "Defines.hpp"
#include <iostream>
#include <ostream>
#include <string>

bool isInteger(const std::string &str) {
  return str.find('.') == std::string::npos;
}

bool leapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int year, int month, int day) {
  if (month < 1 || month > 12)
    return false;

  if (year < 2009 || (year == 2009 && month == 1 && day < 3) ||
      (year == 2022 && day > 29 && month > 03))
    return false;

  int dayInMo[] = {
      31, leapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (day < 1 || day > dayInMo[month - 1])
    return false;

  return true;
}

bool validateDate(const std::string &date) {
  if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    return false;

  std::string year, month, day;
  year = date.substr(0, 4);
  month = date.substr(5, 2);
  day = date.substr(8, 2);

  if (!isValidDate(atoi(year.c_str()), atoi(month.c_str()),
                   atoi(day.c_str()))) {
    return false;
  }
  return true;
}

bool validatePrice(double value) {
  if (value < 0) {
    std::cerr << RED("Error: ") << CYAN("not a positive number.") << std::endl;
    return false;
  } else if (value > 1000) {
    std::cerr << RED("Error: ") << CYAN("too large a number.") << std::endl;
    return false;
  }
  return true;
}

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
