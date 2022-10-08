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
	_hp = hp;
}

void	ClapTrap::setEp(int ep)
{
	_ep = ep;
}

void	ClapTrap::setAd(int ad)
{
	_ad = ad;
}

int		ClapTrap::getHp(void) const
{
	return (_hp);
}

int		ClapTrap::getEp(void) const
{
	return (_ep);
}

int		ClapTrap::getAd(void) const
{
	return (this->_ad);
}

std::string	ClapTrap::getName(void) const
{
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
		std::cout << "no Energy points (" << _ep << ") for attack!\n";
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