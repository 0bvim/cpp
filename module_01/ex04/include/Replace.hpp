#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>

class Replace {

public:
	Replace(std::string original, std::string search, std::string replace);
	~Replace();

	void replaceOut();

private:
	std::string _toReplace;
	std::string _search;
	std::string _replace;
};

#endif // !REPLACE_HPP
