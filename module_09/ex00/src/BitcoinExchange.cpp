#include "BitcoinExchange.hpp"
#include "Defines.hpp"
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

static bool isInteger(const std::string &str) {
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

static bool validateDate(const std::string &date) {
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

static bool validatePrice(float value) {
  if (value < 0.0) {
    OUTNL(RED("Error: ") << "not a positive number.");
    return false;
  } else if (value > 1000.0) {
    OUTNL(RED("Error: ") << "too large a number.");
    return false;
  }
  return true;
}

Exchange::Exchange() : _bitcoinPrices(0) {}

Exchange::Exchange(const std::string &file) : _bitcoinPrices(0) {
  std::ifstream fl(file.c_str());
  if (!fl.is_open())
    throw std::runtime_error("could not open file.\n");

  std::string line, beforeComma, afterComma;
  std::getline(fl, line);
  while (std::getline(fl, line)) {
    size_t pos = line.find(',');
    if (pos != std::string::npos) {
      if (!validateDate(line.substr(0, pos))) {
        std::cerr << RED("Error: ") << "bad input => "
                  << line.substr(0, pos) + "\n";
        continue;
      }
      beforeComma = line.substr(0, pos);
      afterComma = line.substr(pos + 1);
      BitcoinPrice bitcoinPrice;
      bitcoinPrice.date = beforeComma;
      isInteger(afterComma)
          ? bitcoinPrice.price = std::atoi(afterComma.c_str())
          : bitcoinPrice.fprice = std::atof(afterComma.c_str());
      if (!validatePrice(bitcoinPrice.fprice) ||
          !validatePrice(bitcoinPrice.price))
        std::cerr << RED("Error: ") << line.substr(0, pos) + "\n";

      this->_bitcoinPrices.push_back(bitcoinPrice);
    }
  }
  fl.close();
}

Exchange::~Exchange() {}

Exchange::Exchange(const Exchange &rhs) { *this = rhs; }

Exchange &Exchange::operator=(const Exchange &rhs) {
  if (this != &rhs) {
    this->_bitcoinPrices = rhs._bitcoinPrices;
  }
  return *this;
}
