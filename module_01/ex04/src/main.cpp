#include "Files.hpp"
#include "Replace.hpp"
#include <cstdlib>
#include <iostream>

#define FILE argv[1]
#define OLD argv[2]
#define NEW argv[3]
#define EMPTY "Empty strings not allowed.\n"
#define USAGE "3 arguments needed: <file> <old string> <new string>.\n"

static bool check_args(std::string a1, std::string a2, std::string a3) {
  if (a1.empty() || a2.empty() || a3.empty()) {
    std::cerr << EMPTY << USAGE;
    return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  (void)argv;
  if (argc != 4) {
    std::cerr << USAGE;
  } else if (check_args(FILE, OLD, NEW)) {
    Files files(argv[1]);
    Replace replace(files.fileReader(), OLD, NEW, FILE);
    replace.replaceOut();
  }
  return EXIT_SUCCESS;
}
