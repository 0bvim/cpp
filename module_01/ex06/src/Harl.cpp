#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level) {
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  for (int i = 0; i < 4; ++i) {
    if (!level.compare(levels[i]))
      this->select = i;
  }
  switch (this->select) {
  case DEBUG:
    debug();
    info();
    warning();
    error();
    break;
  case INFO:
    info();
    warning();
    error();
    break;
  case WARNING:
    warning();
    error();
    break;
  case ERROR:
    error();
    break;
  default:
    std::cout << "Invalid entry." << std::endl;
  }
}

void Harl::debug(void) {
  std::cout
      << "[DEBUG]\n"
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
      << std::endl;
}

void Harl::info(void) {
  std::cout
      << "[INFO]\n"
      << "I cannot believe adding extra bacon costs more money. You didn’t put "
         "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
      << std::endl;
}

void Harl::warning(void) {
  std::cout
      << "[WARNING]\n"
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming for years whereas you started working here since last month."
      << std::endl;
}

void Harl::error(void) {
  std::cout << "[ERROR]\n"
            << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}
