#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("Random animal")
{
	std::cout << GREEN << "Animal" << END << ": Default " << GREEN
				<< "constructor" << END << " called\n";
	return ;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << GREEN << "Animal" << END << ": String " << GREEN
				<< "constructor" << END<< " called\n";
	return ;
}

AAnimal::~AAnimal(void)
{
	std::cout << GREEN << "Animal" << END << ": " << RED << "Destructor"
				<< END << " called\n";
}

AAnimal::AAnimal(const AAnimal &animal)
{
	std::cout << GREEN << "Animal" << END << ": Copy constructor called\n";
	*this = animal;
}

std::string	AAnimal::getType(void) const
{
	return (_type);
}

AAnimal	&AAnimal::operator = (const AAnimal &animal)
{
	_type = animal.getType();
	std::cout << GREEN << "Animal" << END << ": Copy assignment operator called\n";
	return (*this);
}

void	AAnimal::setType(const std::string type)
{
	_type = type;
}
