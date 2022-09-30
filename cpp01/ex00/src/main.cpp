#include "Zombie.hpp"

int	main(void)
{
	Zombie	z1("monster");
	Zombie	*z2;
	Zombie	z3("lol");

	z2 = newZombie("kek");
	randomChump("dead");
	z2->announce();
	delete z2;
	z2 = &z3;
	z2->announce();
	for (int i=0; i < 1000; ++i)
	{
		std::cout << i << '\n';
		z2 = newZombie("zombie2");
		delete z2;
		randomChump("zombie");
	}
}
