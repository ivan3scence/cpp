#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure	*Cure::clone(void) const
{
	Cure	*clon = new Cure();

	return (clon);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "*heals " << target.getName() << "'s wounds *\n";
}

Cure::~Cure(void)
{
	return ;
}

Cure::Cure(Cure const &cure)
{
	*this = cure;
}

Cure	&Cure::operator = (const Cure &cure)
{
	if (this == &cure)
		return (*this);
	_type = cure.getType();
	return (*this);
}