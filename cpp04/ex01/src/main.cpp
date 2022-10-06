#include "Dog.hpp"
#include "Cat.hpp"

# define ARRAY 100

int main( void ) {
	Animal	*animals[ARRAY];


	for (int i=0; i < ARRAY / 2; ++i)
	{
		animals[i] = new Dog();
		animals[ARRAY - 1 - i] = new Cat();
	}
	for (int i=0; i < ARRAY / 2; ++i)
	{
		delete animals[i];
		delete animals[ARRAY - 1 - i];
	}
	return 0;
}
