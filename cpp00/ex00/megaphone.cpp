#include <iostream>
#include <cstring>

int	main(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		for (size_t j = 0; j < strlen(argv[i]); ++j)
		{
			std::cout << (char)toupper(argv[i][j]);
		}
		if (argv[i + 1])
			std::cout << ' ';
	}
	std::cout << std::endl;
}
