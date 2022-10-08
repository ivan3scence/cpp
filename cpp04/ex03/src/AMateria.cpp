#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	_type = type;
}

AMateria::AMateria(void) {}

AMateria::AMateria(const AMateria &amateria)
{
	*this = amateria;
}

AMateria	&AMateria::operator = (AMateria const &amateria)
{
	if (this == &amateria)
		return (*this);
	_type = amateria.getType();
	return (*this);
}

AMateria::~AMateria(void)
{
	return ;
}

std::string const &AMateria::getType(void) const
{
	return (_type);
}