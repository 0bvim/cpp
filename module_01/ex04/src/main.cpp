#include "Files.hpp"
#include "Replace.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  (void)argv;
  if (argc != 4) {
    std::cerr << "3 arguments needed: <file> <old string> <new string2>"
              << std::endl;
  } else {
    Files files(argv[1]);
    Replace replace(files.fileReader(), argv[2], argv[3]);
    replace.replaceOut();
    /* std::cout << files.fileReader() << std::endl; */
  }
  return EXIT_SUCCESS;
}
