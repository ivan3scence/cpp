#ifndef __HUMANA_H__
#define __HUMANA_H__

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
public:

	HumanA(std::string name, const Weapon &weapon);
	~HumanA(void);

	const std::string	&getType(void) const;
	void				setType(std::string new_type);
	void				attack(void) const;

private:
	std::string			_name;
	const Weapon		&_weapon;
};

#endif
