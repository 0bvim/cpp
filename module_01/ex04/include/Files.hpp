#ifndef FILES_HPP
#define FILES_HPP

#include <string>

class Files {

public:
	Files(const std::string& name);
	~Files();

	std::string fileReader();

private:
	std::string fileName;
};

#endif // !FILES_HPP
