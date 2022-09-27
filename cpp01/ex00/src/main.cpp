#include "Zombie.hpp"

int	main(void)
{
	Zombie	z1("monster");
	Zombie	*z2;
	Zombie	z3("lol");

	z2 = newZombie("kek");
	randomChump("dead");
	z2->announce();
	z2 = &z3;
	z2->announce();
	for (int i=0; i < 1000000; ++i)
	{
		std::cout << i << ": ";
		randomChump("gg");
	}
}