#include <cstring>
#include <gtest/gtest.h>
#include <memory>
#include <string>

// Function to create a argv ez.
std::unique_ptr<char *[]>
createArgv(const std::initializer_list<std::string> &args) {
  auto argv = std::make_unique<char *[]>(args.size());
  size_t i = 0;
  for (const auto &arg : args) {
    argv[i] = new char[arg.length() + 1]; // +1 for null terminator
    std::strcpy(argv[i], arg.c_str());
    ++i;
  }
  return argv;
}

std::string processArgs(int argc, char **argv);
/**
 * this is the way that you test a function without class
 * you declare the function like I made above
 * then just make assert and expected result
 **/
TEST(processArgs, NoArgs) {
  auto argv = createArgv({"program name", ""});
  std::string result = processArgs(2, argv.get());
  EXPECT_EQ(result, "* LOUD AND UNBEARABLE FEEDBACK NOISE *");
}

TEST(processArgs, SingleArgument) {
  auto argv = createArgv({"program name", "hello"});
  std::string result = processArgs(2, argv.get());
  EXPECT_EQ(result, "HELLO");
}

TEST(processArgs, MultiArgs) {
  auto argv = createArgv({"program name", "hello "
                                          "world!"
                                          " How are you?"});
  std::string result = processArgs(2, argv.get());
  EXPECT_EQ(result, "HELLO WORLD! HOW ARE YOU?");
}

TEST(processArgs, NumberArguments) {
  auto argv = createArgv({"program name", "123123", "89807", "AB2c3d"});
  std::string result = processArgs(4, argv.get());
  EXPECT_EQ(result, "12312389807AB2C3D");
}
