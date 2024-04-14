#ifndef FILES_HPP
#define FILES_HPP

#include <fstream>
#include <string>

class Files {

public:
	Files();
	~Files();

	void openFile();
	std::string readFile();
	void setFileName(std::string const name);
	std::string getFileName();

private:
	std::string _fileName;
	std::ifstream _file;
};

#endif // !FILES_HPP
