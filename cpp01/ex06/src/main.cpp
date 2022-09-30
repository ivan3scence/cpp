#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		exit(1);
	}
	harl.complain(argv[1]);
}
