#include "HumanA.hpp"

HumanA::HumanA(std::string name, const Weapon &weapon) : _name(name), _weapon(weapon)
{
	return ;
}

HumanA::~HumanA(void)
{
	// std::cout << _name << " was destructed\n";
}

void	HumanA::attack(void) const
{
	std::cout << _name << "  attacks with their " << _weapon.getType() << std::endl;
}
