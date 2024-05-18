#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <deque>
#include <string>

struct BitcoinPrice {
  std::string date;
  double price;
};

class Exchange {
private:
  std::deque<BitcoinPrice> _bitcoinPrices;

public:
  Exchange();
  ~Exchange();
  Exchange(const Exchange &rhs);
  Exchange &operator=(const Exchange &rhs);

  void inputValidation(const std::string &file);
  std::deque<BitcoinPrice>::iterator findClosestDate(const std::string &date);
};

#endif // BITCOINEXCHANGE_HPP
