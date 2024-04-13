#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
	
private:
	std::string _type;

public:
	Weapon();
	~Weapon();

	const std::string& getType() const;
	void	setType(const std::string& name);
};

#endif  // INCLUDE_INCLUDE_WEAPON_HPP_
