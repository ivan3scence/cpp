#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

# include <iostream>
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define GRAY "\x1B[90m"
# define END "\033[0m"

class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(std::string name, int hp, int ep, int ad);
	ClapTrap(const ClapTrap &ct);
	~ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap	&operator = (const ClapTrap &ct);

	void		attack(const std::string &targer);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

	int			getHp(void) const;
	int			getEp(void) const;
	int			getAd(void) const;
	std::string	getName(void) const;

	void		setHp(int hp);
	void		setEp(int ep);
	void		setAd(int ad);
protected:
	std::string	_name;
	int			_hp;
	int			_ep;
	int			_ad;
};

#endif
