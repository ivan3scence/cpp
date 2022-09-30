#ifndef __HUMANB_H__
#define __HUMANB_H__

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
public:

	HumanB(void);
	HumanB(std::string name);
	HumanB(std::string name, Weapon &weapon);
	HumanB(std::string name, Weapon *weapon);
	~HumanB(void);

	const std::string	&getType(void) const;
	void				setType(std::string new_type);
	void				attack(void) const;
	void				setWeapon(Weapon &weapon);

private:
	std::string			_name;
	Weapon				*_weapon;
};

#endif
