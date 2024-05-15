#include "Defines.hpp"
#include "MutantStack.h"
#include <iostream>

void myTest() {
	NL;
  MutantStack<int> mstack;

  // Test pushing elements
  mstack.push(5);
  mstack.push(17);
  mstack.push(10);

  // Test popping elements
  std::cout << "Stack after pushing 5, 17, 10:" << std::endl;
  while (!mstack.empty()) {
    std::cout << mstack.top() << std::endl;
    mstack.pop();
  }
  std::cout << std::endl;

  // Test pushing and popping mixed with iteration
  for (int i = 0; i < 5; ++i) {
    mstack.push(i * 2);
  }
  std::cout << "Stack after pushing 0, 2, 4, 6, 8:" << std::endl;
  for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end();
       ++it) {
    std::cout << *it << std::endl;
    if (*it % 4 == 0) {
      mstack.pop();
    }
  }
  std::cout << std::endl;

  // Test copying the stack
  MutantStack<int> copiedStack = mstack;
  std::cout << "Copied stack:" << std::endl;
  for (MutantStack<int>::iterator it = copiedStack.begin();
       it != copiedStack.end(); ++it) {
    std::cout << *it << std::endl;
  }
  std::cout << std::endl;
}

void subjectTest() {
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

int main() {
  myTest();
  subjectTest();

  return 0;
}
