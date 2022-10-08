#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::~Ice(void)
{
	return ;
}

Ice::Ice(Ice const &ice)
{
	*this = ice;
}

Ice	&Ice::operator = (const Ice &ice)
{
	if (this == &ice)
		return (*this);
	_type = ice.getType();
	return (*this);
}

Ice	*Ice::clone(void) const
{
	Ice	*clon = new Ice();

	return (clon);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "*shoots an ice bolt at " << target.getName() << " *\n";
}
