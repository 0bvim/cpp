#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {

public:
  Harl();
  ~Harl();

  enum ComplaintLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
  };

  void complain(std::string level);

private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
	size_t select;
};

#endif // !HARL_HPP
