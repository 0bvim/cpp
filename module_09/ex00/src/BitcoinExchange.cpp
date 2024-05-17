#include "BitcoinExchange.hpp"
#include "Defines.hpp"
#include "utils.h"
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

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

void Exchange::inputValidation(const std::string &date) { (void)date; }
