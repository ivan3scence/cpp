#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Lol", 100, 100, 30)
{
	std::cout << BLUE << "FragTrap" << END << ": default constructor called\n";
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << BLUE << "FragTrap" << END << ": String constructor called\n";
	return ;
}

FragTrap::FragTrap(std::string name, int hp,
					int ep, int ad) : ClapTrap(name, hp, ep, ad)
{
	std::cout << BLUE << "FragTrap" << END << ": Ints constructor called\n";
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << BLUE << "FragTrap" << END << ": Destructor called\n";
}

FragTrap::FragTrap(const FragTrap &st) : ClapTrap(st)
{
	std::cout << BLUE << "FragTrap" << END << ": copy constructor called\n";
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
		std::cout << BLUE << "FragTrap" << END << ": no Energy points (" << this->getEp() << ") for attack!n";
		return ;
	}
	this->_ep -= this->_ad;
	std::cout << BLUE << "FragTrap" << END << ": " << this->getName() << " attacks "<< target << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << BLUE << "FragTrap" << END << ":" << this->getName() << " gives High Five!\n";
}
