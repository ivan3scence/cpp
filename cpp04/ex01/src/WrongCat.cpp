#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << YELLOW << _type << END << ": Default " << GREEN
				<< "constructor" << END << " called\n";
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << YELLOW << _type << END << ": " << RED << "Destructor"
				<< END << " called\n";
}

WrongCat::WrongCat(const WrongCat &WrongCat)
{
	std::cout << YELLOW << _type << END << ": Copy constructor called\n";
	this->_type = "WrongCat";
	*this = WrongCat;
}

WrongCat	&WrongCat::operator = (const WrongCat &animal)
{
	std::cout << YELLOW << _type << END << ": Copy assignment operator called\n";
	(void)animal;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << YELLOW << _type << END << ": MEOW! MEOW!\n";
}
