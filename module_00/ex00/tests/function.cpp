#include <string>
#include <cstring>

std::string processArgs(int argc, char **argv) {
  if (argc > 1 && strcmp(argv[1], "")) {
    std::string result;
    for (int i = 1; i < argc; i++) {
      std::string str(argv[i]);
      for (size_t len = 0; len < str.size(); len++)
        str[len] = std::toupper(str[len]);
      result += str;
    }
    return result;
  } else
    return "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
}
