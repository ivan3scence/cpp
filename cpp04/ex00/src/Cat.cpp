#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << YELLOW << _type << END << ": Default " << GREEN
				<< "constructor" << END << " called\n";
	return ;
}

Cat::~Cat(void)
{
	std::cout << YELLOW << _type << END << ": " << RED << "Destructor"
				<< END << " called\n";
}

Cat::Cat(const Cat &Cat)
{
	std::cout << YELLOW << _type << END << ": Copy constructor called\n";
	this->_type = "Cat";
	*this = Cat;
}

Cat	&Cat::operator = (const Cat &animal)
{
	std::cout << YELLOW << _type << END << ": Copy assignment operator called\n";
	(void)animal;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << YELLOW << _type << END << ": MEOW! MEOW!\n";
}
