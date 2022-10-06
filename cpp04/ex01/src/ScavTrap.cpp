#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Lol", 100, 50, 20)
{
	std::cout << YELLOW << "ScavTrap" << END << ": default constructor called\n";
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << YELLOW << "ScavTrap" << END << ": String constructor called\n";
	return ;
}

ScavTrap::ScavTrap(std::string name, int hp,
					int ep, int ad) : ClapTrap(name, hp, ep, ad)
{
	std::cout << YELLOW << "ScavTrap" << END << ": Ints constructor called\n";
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << YELLOW << "ScavTrap" << END << ": Destructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st)
{
	std::cout << YELLOW << "ScavTrap" << END << ": copy constructor called\n";
}

ScavTrap	&ScavTrap::operator = (const ScavTrap &ct)
{
	std::cout << YELLOW << "ScavTrap" << END << ": Copy assignment operator called\n";
	_hp = ct.getHp();
	_ep = ct.getEp();
	_ad = ct.getAd();
	_name = ct.getName();
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_ep < this->_ad)
	{
		std::cout << YELLOW << "ScavTrap" << END << ":no Energy points (" << this->getEp() << ") for attack!n";
		return ;
	}
	this->_ep -= this->_ad;
	std::cout << YELLOW << "ScavTrap" << END << ":" << this->getName() << " attacks "<< target << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << YELLOW << "ScavTrap" << END << ":" << this->getName() << " is in Gate keeper mode!\n";
}
