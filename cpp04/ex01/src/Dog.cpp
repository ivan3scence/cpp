#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << PURPLE << "Dog" << END << ": Default " << GREEN
				<< "constructor" << END << " called\n";
	_brain = new Brain("dog");
	return ;
}

Dog::~Dog(void)
{
	std::cout << PURPLE << "Dog" << END << ": " << RED << "Destructor"
				<< END << " called\n";
	delete _brain;
}

Dog::Dog(const Dog &Dog)
{
	std::cout << PURPLE << "Dog" << END << ": Copy constructor called\n";
	this->_type = "Dog";
	_brain = NULL;
	*this = Dog;
}

Brain	&Dog::getBrain(void) const
{
	return (*_brain);
}

Dog	&Dog::operator = (const Dog &animal)
{
	std::cout << PURPLE << "Dog" << END << ": Copy assignment operator called\n";
	if (_brain)
		delete _brain;
	_brain = new Brain(animal.getBrain());
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << PURPLE << "Dog" << END << ": WOOF! WOOF!\n";
}
