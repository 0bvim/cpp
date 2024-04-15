#include "Files.hpp"
#include "Replace.hpp"
#include <cstdlib>
#include <iostream>

#define FILE argv[1]
#define OLD argv[2]
#define NEW argv[3]

int main(int argc, char *argv[]) {
  (void)argv;
  if (argc != 4) {
    std::cerr << "3 arguments needed: <file> <old string> <new string>"
              << std::endl;
  } else {
    Files files(argv[1]);
    Replace replace(files.fileReader(), OLD, NEW, FILE);
    replace.replaceOut();
  }
  return EXIT_SUCCESS;
}
