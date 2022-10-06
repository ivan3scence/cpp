#ifndef __DIAMONDTRAP_H__
#define __DIAMONDTRAP_H__

# include <iostream>

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(const DiamondTrap &dt);
	~DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap	&operator = (const DiamondTrap &ct);

	void		whoAmI(void);

	using 		ScavTrap::attack;

private:
	DiamondTrap(void);

	std::string	_name;
};

#endif
