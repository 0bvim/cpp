#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <deque>
#include <string>

struct BitcoinPrice {
  std::string date;
  float fprice;
  int price;
};

class Exchange {
private:
  std::deque<BitcoinPrice> _bitcoinPrices;
  Exchange();

public:
  Exchange(const std::string &file);
  ~Exchange();
  Exchange(const Exchange &rhs);
  Exchange &operator=(const Exchange &rhs);
};

#endif // BITCOINEXCHANGE_HPP
