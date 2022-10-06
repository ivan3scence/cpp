#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << GRAY << "DiamondTrap" << END
				<< ": default constructor called\n";
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
												ScavTrap(name), FragTrap(name)
{
	std::cout << GRAY << "DiamondTrap" << END
				<< ": String constructor called\n";
	_name = name;
	_ep = 50;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << GRAY << "DiamondTrap" << END << ": Destructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &dt)
{
	std::cout << GRAY << "DiamondTrap" << END << ": copy constructor called\n";
	*this = dt;
}

DiamondTrap	&DiamondTrap::operator = (const DiamondTrap &ct)
{
	std::cout << GRAY << "DiamondTrap" << END
				<< ": Copy assignment operator called\n";
	_hp = ct.getHp();
	_ep = ct.getEp();
	_ad = ct.getAd();
	_name = ct.getName();
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << GRAY << "DiamondTrap" << END << " call me "
				<< PURPLE << _name << END << " or " << ORANGE
				<< ClapTrap::_name << END << std::endl;
}
