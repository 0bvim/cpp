#include "BitcoinExchange.hpp"
#include "Defines.hpp"
#include "utils.h"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <deque>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

Exchange::Exchange() : _bitcoinPrices(std::deque<BitcoinPrice>()) {
  std::ifstream fl("data.csv");
  if (!fl.is_open())
    throw std::runtime_error("could not open database file.\n");

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
std::deque<BitcoinPrice>::iterator
Exchange::findClosestDate(const std::string &date) {
  if (_bitcoinPrices.empty()) {
    return _bitcoinPrices.end();
  }

  std::deque<BitcoinPrice>::iterator closestIt = _bitcoinPrices.end();
  long long minDiff = LLONG_MAX;

  for (std::deque<BitcoinPrice>::iterator it = _bitcoinPrices.begin();
       it != _bitcoinPrices.end(); ++it) {
    long long diff = std::labs(it->date.compare(date));
    if (diff < minDiff) {
      minDiff = diff;
      closestIt = it;
    }
  }

  return closestIt;
}

void Exchange::inputValidation(const std::string &file) {
  std::ifstream fl(file.c_str());
  if (!fl.is_open())
    throw std::runtime_error("could not open input file.\n");

  std::string line, date, rate;
  std::getline(fl, line);
  while (std::getline(fl, line)) {
    if (line.find('|') == std::string::npos) {
      std::cerr << RED("Error: ") << YELLOW("bad input => " << line)
                << std::endl;
      continue;
    }
    date = trim(line.substr(0, line.find('|')));
    rate = trim(line.substr(line.find('|') + 1));

    if (validateDate(date) && validatePrice(atof(rate.c_str()))) {
      double rateValue = atof(rate.c_str());
      std::deque<BitcoinPrice>::iterator it = findClosestDate(date);
      if (it != _bitcoinPrices.end()) {
        double result = it->price * rateValue;
        OUTNL(date << " => " << it->price << " = " << result);
      }
    }
  }
}
