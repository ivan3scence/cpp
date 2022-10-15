#include "Base.hpp"
#include "C.hpp"
#include "B.hpp"
#include "A.hpp"
#include <iostream>

Base	*generate(void)
{
	int		i;

	i = std::rand() % 3;
	if (i == 0)
	{
		std::cout << "crated A-class object\n";
		return (new A());
	}
	else if (i == 1)
	{
		std::cout << "crated B-class object\n";
		return (new B());
	}
	std::cout << "crated C-class object\n";
	return (new C());
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "this object from 'A'-class\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "this object from 'B'-class\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "this object from 'C'-class\n";
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "this object from 'A'-class\n";
	}
	catch (const std::exception&) {}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "this object from 'B'-class\n";
	}
	catch (const std::exception &){}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "this object from 'C'-class\n";
	}
	catch (const std::exception&) {}
}

int	main(void)
{
	std::srand(std::time(0));
	Base	*o1 = generate();
	Base	*o2 = generate();
	Base	*o3 = generate();

	identify(o1);
	identify(o2);
	identify(o3);

	Base	&o4 = *o1;
	Base	&o5 = *o2;
	Base	&o6 = *o3;

	identify(o4);
	identify(o5);
	identify(o6);
}
