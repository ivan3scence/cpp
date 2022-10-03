#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

# include <iostream>

class ClapTrap
{
public:

	ClapTrap(void);
	ClapTrap(const ClapTrap &ct);
	~ClapTrap(void);
	ClapTrap(std::string name);

	int			getRawBits(void) const;
	void		setRawBits(int const raw);
	void		attack(const std::string &targer);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

private:
	int			_hp;
	int			_ep;
	int			_ad;
};

#endif
