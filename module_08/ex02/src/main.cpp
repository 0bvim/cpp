#include "Defines.hpp"
#include "MutantStack.h"
#include <iostream>
#include <list>

template <typename T> void printStack(MutantStack<T> &mstack) {
  while (!mstack.empty()) {
    std::cout << YELLOW(mstack.top()) << std::endl;
    mstack.pop();
  }
  std::cout << RED("Poping values from stack to another round") << std::endl;
  NL;
}

void myTest() {
  NL;
  std::cout << BLACK("========== My test with MutantStack ==========")
            << std::endl;
  MutantStack<int> mstack;

  // Test pushing elements
  mstack.push(5);
  mstack.push(17);
  mstack.push(10);

  // Test popping elements
  std::cout << GREEN("Stack after pushing 5, 17, 10:") << std::endl;
  printStack(mstack);

  // Test pushing and popping mixed with iteration
  for (int i = 0; i < 5; ++i) {
    mstack.push(i * 2);
  }
  std::cout << GREEN("Stack after pushing 0, 2, 4, 6, 8:") << std::endl;
  printStack(mstack);

  std::cout << RED("Adding itens to original stack") << std::endl;
  for (int i = 0; i < 15; ++i) {
    mstack.push(i * 3);
  }
  NL;
  // Test copying the stack
  std::cout << MAGENTA("Copying the original stack to another") << std::endl;
  MutantStack<int> copiedStack = mstack;
  NL;
  std::cout << GREEN("Values of original stack") << std::endl;
  printStack(mstack);
  std::cout << YELLOW("Copied stack:") << std::endl;
  printStack(copiedStack);
}

void subjectTest() {
  NL;
  std::cout << BLACK(" === SUBJECT TESTS === ") << std::endl;
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
}

template <typename T> void printStackList(std::list<T> &mylist) {
  while (!mylist.empty()) {
    std::cout << YELLOW(mylist.back()) << std::endl;
    mylist.pop_back();
  }
  std::cout << RED("Poping values from stack for another round") << std::endl;
  std::cout << std::endl;
}

void myTestList(void) {
  std::cout << std::endl;
  std::cout << BLACK("========== My test with List ==========") << std::endl;
  std::list<int> mylist; // Use std::list instead of MutantStack

  // Test pushing elements
  mylist.push_back(5);
  mylist.push_back(17);
  mylist.push_back(10);

  // Test popping elements
  std::cout << "\033[32mStack after pushing 5, 17, 10:\033[0m" << std::endl;
  printStackList(mylist);

  // Test pushing and popping mixed with iteration
  for (int i = 0; i < 5; ++i) {
    mylist.push_back(i * 2);
  }
  std::cout << "\033[32mStack after pushing 0, 2, 4, 6, 8:\033[0m" << std::endl;
  printStackList(mylist);

  std::cout << "\033[31mAdding items to the original stack\033[0m" << std::endl;
  for (int i = 0; i < 15; ++i) {
    mylist.push_back(i * 3);
  }
  std::cout << std::endl;

  // Test copying the stack
  std::cout << "\033[35mCopying the original stack to another\033[0m"
            << std::endl;
  std::list<int> copiedList = mylist;
  std::cout << std::endl;

  std::cout << "\033[32mValues of the original stack\033[0m" << std::endl;
  printStackList(mylist);
  std::cout << "\033[33mCopied stack:\033[0m" << std::endl;
  printStackList(copiedList);
}

void listTest(void) {
  NL;
  std::cout << BLACK(" === LIST TESTS === ") << std::endl;
  std::list<int> mylist; // Use std::list instead of MutantStack

  // Test pushing elements
  mylist.push_back(5);
  mylist.push_back(17);

  // Test top, pop, and size
  std::cout << mylist.back() << std::endl;
  mylist.pop_back();
  std::cout << mylist.size() << std::endl;

  // Test pushing more elements
  mylist.push_back(3);
  mylist.push_back(5);
  mylist.push_back(737);
  mylist.push_back(0);

  // Iterate over the list
  std::list<int>::iterator it = mylist.begin();
  std::list<int>::iterator ite = mylist.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
}

int main() {
  myTest();
  myTestList();
  subjectTest();
  listTest();

  return 0;
}
