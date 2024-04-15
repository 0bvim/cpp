#include "Replace.hpp"

Replace::Replace(std::string original, std::string search, std::string replace)
    : _toReplace(original), _search(search), _replace(replace) {}
