#include <iostream>
#include <sstream>
#include <string>

void istremTest(std::string str) {
  // Create an istringstream object
  std::istringstream iss(str);

  // Extract the numeric part using getline with ',' as delimiter
  std::string date;
  std::getline(iss, date, ',');

	
	std::string price;
  std::getline(iss, price, ',');

}

int main() {
  std::string str = "2009-19-20,2912.2";
  std::string str1 = "2009-19-20,2912.0f";
  std::string str2 = "2009-19-20,2912.00000000";

  istremTest(str);
  istremTest(str1);
  istremTest(str2);

  return 0;
}
