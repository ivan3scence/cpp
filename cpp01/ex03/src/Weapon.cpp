#include "Weapon.hpp"

Weapon::Weapon(void) : _type(NULL)
{
	return ;
}

Weapon::Weapon(std::string type) : _type(type)
{
	return ;
}

Weapon::~Weapon(void)
{
	// std::cout << _type << " was destructed\n";
}

void	Weapon::setType(std::string new_type)
{
	_type = new_type;
}

const std::string	&Weapon::getType(void) const
{
	const std::string	&ref=_type;

	return (ref);
}
