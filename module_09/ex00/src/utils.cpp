#include "utils.h"
#include "Defines.hpp"
#include <iostream>
#include <ostream>

bool isInteger(const std::string &str) {
  return str.find('.') == std::string::npos;
}

bool leapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int year, int month, int day) {
  if (month < 1 || month > 12)
    return false;

  if (year < 2009 || (year == 2009 && month == 1 && day < 3))
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

  try {
    return isValidDate(atoi(year.c_str()), atoi(month.c_str()),
                       atoi(day.c_str()));
  } catch (const std::exception &e) {
    return false;
  }
}

bool validatePrice(double value) {
  if (value < 0) {
    OUTNL(RED("Error: ") << "not a positive number.");
    return false;
  } else if (value > 1000) {
    OUTNL(RED("Error: ") << "too large a number.");
    return false;
  }
  return true;
}
