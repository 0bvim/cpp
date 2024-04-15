#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>

class Replace {

public:
	Replace(std::string original, std::string search, std::string replace, std::string fileName);
	~Replace();

	void replaceOut();

private:
	std::string _toReplace;
	std::string _search;
	std::string _replace;
	std::string _fileName;
};

#endif // !REPLACE_HPP
