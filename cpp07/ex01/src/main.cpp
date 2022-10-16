#include "iter.hpp"
#include <iostream>

#define SIZE 5

template < typename T >
void	print(T elem)
{
	std::cout << elem << std::endl;
}

int main( void )
{
	int		integer[SIZE]={1,2,3,4,5};
	double	dbl[SIZE]={1,2,3,4,5};
	std::string	strs[SIZE]={"1","2","3","4","5"};

	iter(integer, SIZE, &print);
	std::cout << std::endl;
	iter(dbl, SIZE, &print);
	std::cout << std::endl;
	iter(strs, SIZE, &print);
}
