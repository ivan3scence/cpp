#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << BLUE << "FragTrap" << END << ": default constructor called\n";
	_hp = 100;
	_ep = 100;
	_ad = 30;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << BLUE << "FragTrap" << END << ": String constructor called\n";
	_name = name;
	_hp = 100;
	_ep = 100;
	_ad = 30;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << BLUE << "FragTrap" << END << ": Destructor called\n";
}

FragTrap::FragTrap(const FragTrap &ft) : ClapTrap(ft)
{
	std::cout << BLUE << "FragTrap" << END << ": copy constructor called\n";
	*this = ft;
}

FragTrap	&FragTrap::operator = (const FragTrap &ct)
{
	std::cout << BLUE << "FragTrap" << END << ": Copy assignment operator called\n";
	_hp = ct.getHp();
	_ep = ct.getEp();
	_ad = ct.getAd();
	_name = ct.getName();
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (this->_ep < this->_ad)
	{
		std::cout << BLUE << "FragTrap" << END << ": no Energy points (" << this->getEp() << ") for attack!\n";
		return ;
	}
	this->_ep -= this->_ad;
	std::cout << BLUE << "FragTrap" << END << ": " << this->getName() << " attacks "<< target << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << BLUE << "FragTrap" << END << ":" << this->getName() << " gives High Five!\n";
}
