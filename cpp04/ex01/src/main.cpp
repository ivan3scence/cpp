#include "Dog.hpp"
#include "Cat.hpp"

# define ARRAY 2

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

	Cat *cat=new Cat();
	Dog *dog=new Dog();
	Brain	br;

	*cat = *dog;
	std::cout << "Cat's idea (\"";
	cat->getBrain().print();
	std::cout << "\") == Dog's idea (\"";
	dog->getBrain().print();
	std::cout << "\");\n";
	delete cat;
	delete dog;
}
