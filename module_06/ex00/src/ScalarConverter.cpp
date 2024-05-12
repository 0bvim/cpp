#include "ScalarConverter.hpp"
#include "Defines.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &rhs) { *this = rhs; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
	(void)rhs;
	return *this;
}

static void converter(const std::string &str) {

}
