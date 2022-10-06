#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

# include <iostream>

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(const ScavTrap &st);
	~ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap	&operator = (const ScavTrap &ct);

	void		attack(const std::string &targer);
	void		guardGate(void);
};

#endif
