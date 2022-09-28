#include "Zombie.hpp"

int	main(void)
{
	int		N=10;
	Zombie	*zombie;

	zombie = zombieHorde(N, "Bob");
	for (int i = 0; i < N; ++i)
		zombie[i].announce();
	delete[] zombie;
}
