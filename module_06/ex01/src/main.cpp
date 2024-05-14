#include "Data.hpp"
#include "Defines.hpp"
#include "Serializer.hpp"
#include <iostream>

static void printData(const Data *p) {
  std::cout << YELLOW("Name: ") << p->name << std::endl;
  std::cout << YELLOW("Size: ") << p->size << std::endl;
  std::cout << YELLOW("Model: ") << p->model << std::endl;
  std::cout << YELLOW("Height: ") << p->height << std::endl;
  std::cout << YELLOW("Width: ") << p->width << std::endl;
  std::cout << std::endl;
}

int main(void) {
  Data *clothing = new Data();

  clothing->name = "t-shirt";
  clothing->size = 'L';
  clothing->model = 23;
  clothing->height = 70.0;
  clothing->width = 50.0f;

  uintptr_t ptr;

  std::cout << RED("Data before serialize") << std::endl;
  printData(clothing);

  ptr = Serializer::serialize(clothing);

  std::cout << RED("Data after serialize") << std::endl;
  printData(clothing);

  Data *testData;

  testData = Serializer::deserialize(ptr);
  std::cout << RED("Data after deserialize") << std::endl;
  printData(testData);

  delete clothing;

  return 0;
}
