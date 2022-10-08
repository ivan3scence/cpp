#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << YELLOW << "Cat" << END << ": Default " << GREEN
				<< "constructor" << END << " called\n";
	_type = "Cat";
	_brain = new Brain("cat");
	return ;
}

Cat::~Cat(void)
{
	std::cout << YELLOW << "Cat" << END << ": " << RED << "Destructor"
				<< END << " called\n";
	delete _brain;
}

Cat::Cat(const Cat &Cat)
{
	std::cout << YELLOW << "Cat" << END << ": Copy constructor called\n";
	this->_type = "Cat";
	*this = Cat;
}

Brain	&Cat::getBrain(void) const
{
	return (*_brain);
}

Cat	&Cat::operator = (const Cat &animal)
{
	std::cout << YELLOW << "Cat" << END << ": Copy assignment operator called\n";
	_brain = new Brain(animal.getBrain());
	return (*this);
}

Cat	&Cat::operator = (const Dog &dog)
{
	if (_brain)
		delete _brain;
	_brain = new Brain(dog.getBrain());
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << YELLOW << "Cat" << END << ": MEOW! MEOW!\n";
}
