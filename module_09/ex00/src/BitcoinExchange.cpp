#include "BitcoinExchange.hpp"
#include <fstream>
#include <stdexcept>

Exchange::Exchange() : _date(""), _value(0), _rvalue(0), _db(NULL) {}

Exchange::~Exchange() {}

Exchange::Exchange(const Exchange &rhs) { *this = rhs; }

Exchange &Exchange::operator=(const Exchange &rhs) {
  if (this != &rhs) {
    this->_date = rhs._date;
    this->_rvalue = rhs._rvalue;
    this->_value = rhs._value;
    this->_db = rhs._db;
  }
  return *this;
}

void Exchange::openFile(const std::string file) {

  std::ifstream fl(file.c_str());
  if (!fl.is_open()) {
    throw std::logic_error("Error opening file");
    return;
  }
  this->_db = &fl;
}
