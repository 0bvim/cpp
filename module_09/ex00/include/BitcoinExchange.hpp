#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdio>
#include <string>

class Exchange {
private:
  std::string _date;
  float _value;
  int _rvalue;
  FILE _db;

public:
  Exchange();
  Exchange(FILE db);
  ~Exchange();
  Exchange(const Exchange &rhs);
  Exchange &operator=(const Exchange &rhs);
};

#endif // BITCOINEXCHANGE_HPP
