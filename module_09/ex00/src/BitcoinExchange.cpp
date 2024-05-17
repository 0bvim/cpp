#include "BitcoinExchange.hpp"
#include "Defines.hpp"
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

/* static bool isInteger(const std::string &str) { */
/*   return str.find('.') == std::string::npos; */
/* } */

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

/* static bool validateDate(const std::string &date) { */
/*   if (date.size() != 10 || date[4] != '-' || date[7] != '-') */
/*     return false; */
/**/
/*   std::string year, month, day; */
/*   year = date.substr(0, 4); */
/*   month = date.substr(5, 2); */
/*   day = date.substr(8, 2); */
/**/
/*   try { */
/*     return isValidDate(atoi(year.c_str()), atoi(month.c_str()), */
/*                        atoi(day.c_str())); */
/*   } catch (const std::exception &e) { */
/*     return false; */
/*   } */
/* } */
/**/

/* static bool validatePrice(double value) { */
/*   if (value < 0) { */
/*     OUTNL(RED("Error: ") << "not a positive number."); */
/*     return false; */
/*   } else if (value > 1000) { */
/*     OUTNL(RED("Error: ") << "too large a number."); */
/*     return false; */
/*   } */
/*   return true; */
/* } */

Exchange::Exchange() : _bitcoinPrices(std::deque<BitcoinPrice>()) {}

Exchange::Exchange(const std::string &file) : _bitcoinPrices(0) {
  std::ifstream fl(file.c_str());
  if (!fl.is_open())
    throw std::runtime_error("could not open file.\n");

  std::string line, date, price;
  std::getline(fl, line);
  while (std::getline(fl, line)) {
    size_t pos = line.find(',');
    if (pos != std::string::npos) {
      date = line.substr(0, pos);
      price = line.substr(pos + 1);
    }
    BitcoinPrice btPrice;
    btPrice.date = date;
    std::istringstream(price) >> btPrice.price;
    this->_bitcoinPrices.push_back(btPrice);
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
