#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << PURPLE << _type << END << ": Default " << GREEN
				<< "constructor" << END << " called\n";
	_brain = new Brain();
	return ;
}

Dog::~Dog(void)
{
	std::cout << PURPLE << _type << END << ": " << RED << "Destructor"
				<< END << " called\n";
}

Dog::Dog(const Dog &Dog)
{
	std::cout << PURPLE << _type << END << ": Copy constructor called\n";
	this->_type = "Dog";
	*this = Dog;
}

Dog	&Dog::operator = (const Dog &animal)
{
	std::cout << PURPLE << _type << END << ": Copy assignment operator called\n";
	(void)animal;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << PURPLE << _type << END << ": WOOF! WOOF!\n";
}
