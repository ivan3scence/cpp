#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__

# include <iostream>

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(const FragTrap &ft);
	~FragTrap(void);
	FragTrap(std::string name);
	FragTrap	&operator = (const FragTrap &ct);

	void		attack(const std::string &targer);
	void		highFivesGuys(void);
};

#endif
