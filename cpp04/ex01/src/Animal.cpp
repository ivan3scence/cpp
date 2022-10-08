#include "Animal.hpp"

Animal::Animal(void) : _type("Random animal")
{
	std::cout << GREEN << "Animal" << END << ": Default " << GREEN
				<< "constructor" << END << " called\n";
	return ;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << GREEN << "Animal" << END << ": String " << GREEN
				<< "constructor" << END<< " called\n";
	return ;
}

Animal::~Animal(void)
{
	std::cout << GREEN << "Animal" << END << ": " << RED << "Destructor"
				<< END << " called\n";
}

Animal::Animal(const Animal &animal)
{
	std::cout << GREEN << "Animal" << END << ": Copy constructor called\n";
	*this = animal;
}

std::string	Animal::getType(void) const
{
	return (_type);
}

Animal	&Animal::operator = (const Animal &animal)
{
	_type = animal.getType();
	std::cout << GREEN << "Animal" << END << ": Copy assignment operator called\n";
	return (*this);
}

void	Animal::setType(const std::string type)
{
	_type = type;
}

void		Animal::makeSound(void) const
{
	std::cout << GREEN << _type << END << ": ...\n";
}
