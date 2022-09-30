#include "HumanB.hpp"

HumanB::HumanB(void) : _name("no_name")
{
	return ;
}

HumanB::HumanB(std::string name) : _name(name)
{
	return ;
}

HumanB::HumanB(std::string name, Weapon &weapon) : _name(name), _weapon(&weapon)
{
	return ;
}

HumanB::HumanB(std::string name, Weapon *weapon) : _name(name), _weapon(weapon)
{
	return ;
}

HumanB::~HumanB(void)
{
	// std::cout << _name << " was destructed\n";
}

void	HumanB::attack(void) const
{
	if (!_weapon)
		std::cout << _name << " has no weapon!\n";
	else
		std::cout << _name << "  attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
