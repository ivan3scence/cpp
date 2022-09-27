#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " was destructed\n";
}

void Zombie::announce(void)
{
	std::cout << _name << ":  BraiiiiiiinnnzzzZ...\n";
}