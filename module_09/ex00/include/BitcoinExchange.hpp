#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <string>

class Exchange {
private:
  std::string _date;
  float _value;
  int _rvalue;
  std::ifstream *_db;

public:
  Exchange();
  ~Exchange();
  Exchange(const Exchange &rhs);
  Exchange &operator=(const Exchange &rhs);

  void openFile(const std::string file);
  void formatPrint();
};

#endif // BITCOINEXCHANGE_HPP
