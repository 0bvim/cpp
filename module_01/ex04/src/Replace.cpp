#include "Replace.hpp"
#include <iostream>
#include <string>

Replace::Replace(std::string original, std::string search, std::string replace)
    : _toReplace(original), _search(search), _replace(replace) {}

Replace::~Replace() {}

void Replace::replaceOut() {
  size_t pos = 0;

  while ((pos = _toReplace.find(_search, pos)) != std::string::npos) {
    _toReplace = _toReplace.substr(0, pos) + _replace +
                 _toReplace.substr(pos + _search.length());
    pos += _replace.length();
  }
  std::cout << _toReplace << std::endl;
}
