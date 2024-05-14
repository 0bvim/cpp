#ifndef DEFINES_HPP
#define DEFINES_HPP

#define BLACK(text) "\033[1;30m" << text << "\033[0m"
#define RED(text) "\033[1;31m" << text << "\033[0m"
#define GREEN(text) "\033[1;32m" << text << "\033[0m"
#define YELLOW(text) "\033[1;33m" << text << "\033[0m"
#define BLUE(text) "\033[1;34m" << text << "\033[0m"
#define MAGENTA(text) "\033[1;35m" << text << "\033[0m"
#define CYAN(text) "\033[1;36m" << text << "\033[0m"
#define WHITE(text) "\033[1;37m" << text << "\033[0m"
#define NL std::cout << std::endl;

#endif  // DEFINES_HPP
