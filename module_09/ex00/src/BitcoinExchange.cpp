#include "BitcoinExchange.hpp"

Exchange::Exchange() : _date(""), _value(0), _rvalue(0) {}

Exchange::~Exchange() {}

Exchange::Exchange(const Exchange &rhs) { *this = rhs; }

Exchange &Exchange::operator=(const Exchange &rhs) {
  if (this != &rhs) {
    this->_date = rhs._date;
    this->_rvalue = rhs._rvalue;
    this->_value = rhs._value;
  }
  return *this;
}

void Exchange::openFile() {

}

