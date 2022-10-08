#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("Random WrongAnimal")
{
	std::cout << GREEN << _type << END << ": Default " << GREEN
				<< "constructor" << END << " called\n";
	return ;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << GREEN << _type << END << ": String " << GREEN
				<< "constructor" << END<< " called\n";
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << GREEN << _type << END << ": " << RED << "Destructor"
				<< END << " called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
	std::cout << GREEN << _type << END << ": Copy constructor called\n";
	*this = animal;
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

WrongAnimal	&WrongAnimal::operator = (const WrongAnimal &animal)
{
	_type = animal.getType();
	std::cout << GREEN << _type << END << ": Copy assignment operator called\n";
	return (*this);
}

void	WrongAnimal::setType(const std::string type)
{
	_type = type;
}

void		WrongAnimal::makeSound(void) const
{
	std::cout << GREEN << _type << END << ": QUAСK\n";
}
