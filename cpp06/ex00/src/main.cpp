#include "StaticCast.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		Cast	c(argv[1]);
		c.display();
	}
	else
		std::cout << "Error! Too few arguments!\n";
}