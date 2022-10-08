#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	_type = type;
}

AMateria::AMateria(void) {}

std::string const &AMateria::getType(void) const
{
//	std::string const	type=_type;
	return (_type);
}