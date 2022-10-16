#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Default " << GREEN << "constructor" << END << " called\n";
	_hp = 10;
	_ep = 10;
	_ad = 0;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "String " << GREEN << "constructor" << END<< " called\n";
	_hp = 10;
	_ep = 10;
	_ad = 0;
	return ;
}

ClapTrap::ClapTrap(std::string name, int hp,
					int ep, int ad) : _name(name), _hp(hp), _ep(ep), _ad(ad)
{
	std::cout << "Ints " << GREEN << "constructor" << END<< " called\n";
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << RED << "Destructor" << END << " called\n";
}

ClapTrap::ClapTrap(const ClapTrap &ct)
{
	std::cout << "Copy constructor called\n";
	*this = ct;
}

void	ClapTrap::setHp(int hp)
{
	//std::cout << "setHp member function called\n";
	_hp = hp;
}

void	ClapTrap::setEp(int ep)
{
//	std::cout << "setHp member function called\n";
	_ep = ep;
}

void	ClapTrap::setAd(int ad)
{
	//std::cout << "setHp member function called\n";
	_ad = ad;
}

int		ClapTrap::getHp(void) const
{
	//std::cout << "getHp member function called\n";
	return (_hp);
}

int		ClapTrap::getEp(void) const
{
	//std::cout << "getEp member function called\n";
	return (_ep);
}

int		ClapTrap::getAd(void) const
{
	//std::cout << "getAd member function called\n";
	return (_ad);
}

std::string	ClapTrap::getName(void) const
{
	//std::cout << "getName member function called\n";
	return (_name);
}

ClapTrap	&ClapTrap::operator = (const ClapTrap &ct)
{
	std::cout << "Copy assignment operator called\n";
	_hp = ct.getHp();
	_ep = ct.getEp();
	_ad = ct.getAd();
	_name = ct.getName();
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (_ep < _ad)
	{
		std::cout << "no Energy points (" << _ep << ") for attack!n";
		return ;
	}
	_ep -= _ad;
	std::cout << "ClapTrap " << _name << " attacks "<< target << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp < (int)amount)
	{
		amount = _hp;
		_hp = 0;
	}
	else
		_hp -= amount;
	std::cout << "causing " << amount << " points of damage!\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_ep > (int)amount && _hp > 0)
	{
		std::cout << _name << " heals (+" << amount << " HP)"<< std::endl;
		_hp += amount;
		_ep -= amount;
	}
}