#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>

class Exchange {
private:
  std::string _date;
  float _value;
  int _rvalue;

public:
  Exchange();
  ~Exchange();
  Exchange(const Exchange &rhs);
  Exchange &operator=(const Exchange &rhs);

	void openFile();
	void formatPrint();
};

#endif // BITCOINEXCHANGE_HPP
