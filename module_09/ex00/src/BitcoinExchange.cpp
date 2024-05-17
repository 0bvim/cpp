#include "BitcoinExchange.hpp"
#include "Defines.hpp"
#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

static bool isInteger(const std::string& str) {
    return str.find('.') == std::string::npos;
}

Exchange::Exchange() : _bitcoinPrices(0) {}

Exchange::Exchange(const std::string &file) {
  std::ifstream fl(file.c_str());
  if (!fl.is_open())
    throw std::runtime_error("could not open file.\n");

  std::string line, beforeComma, afterComma;
  std::getline(fl, line);
  while (std::getline(fl, line)) {
		size_t pos = line.find('.');
		if (pos != std::string::npos) {
			beforeComma = line.substr(0, pos);
			afterComma = line.substr(pos + 1);
		}
    BitcoinPrice bitcoinPrice;
    bitcoinPrice.date = beforeComma;
    bitcoinPrice.price = price;
    this->_bitcoinPrices.push_back(bitcoinPrice);
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
