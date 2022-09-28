#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombie;

	zombie = new Zombie[N];
	for (int i = 0; i < N; ++i)
		zombie[i].setName(name + " " + std::to_string(i + 1));
	return (zombie);
}
