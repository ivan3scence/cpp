#include "Array.hpp"
#include <iostream>

#define SIZE 5

int main(void)
{
	Array<int> a=Array<int>(SIZE);

	for (int i=0; i < SIZE; ++i)
		a[i] = i;
	for (int i=0; i < SIZE; ++i)
		std::cout << a[i] << ":";
	std::cout << std::endl;
	for (int i=-1; i <= SIZE; ++i)
	{
		try {
			std::cout << a[i] << ":";
		}
		catch (const std::exception &e) {
			std::cerr << e.what();
		}
	}

	Array<double>	b;
}
