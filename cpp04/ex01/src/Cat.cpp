#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << YELLOW << _type << END << ": Default " << GREEN
				<< "constructor" << END << " called\n";
	_brain = new Brain();
	return ;
}

Cat::~Cat(void)
{
	std::cout << YELLOW << _type << END << ": " << RED << "Destructor"
				<< END << " called\n";
	delete _brain;
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
	*_brain = animal.getBrain();
	return (*this);
}

//std::string *Cat::getBrainIdeas(void)
//{
//	std::string ids[100];
//	std::string *brain_ideas=_brain->getIdeas();
//
//	for (int i=0; i < 100; ++i)
//		ids[i] = brain_ideas[i];
//	return (ids);
//}

void Cat::makeSound(void) const
{
	std::cout << YELLOW << _type << END << ": MEOW! MEOW!\n";
}
