#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

# include <iostream>

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string name, int hp, int ep, int ad);
	ScavTrap(const ScavTrap &st);
	~ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap	&operator = (const ScavTrap &ct);

	void		attack(const std::string &targer);
	void		guardGate(void);

protected:
	std::string	_name;
	int			_hp;
	int			_ep;
	int			_ad;
};

#endif
