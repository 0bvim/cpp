#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
	
private:
	std::string _type;

public:
	Weapon(const std::string& name);
	~Weapon();

	const std::string& getType();
	void	setType(std::string name);
};

#endif  // INCLUDE_INCLUDE_WEAPON_HPP_
