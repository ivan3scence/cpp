#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << GREEN << "Brain" << END << ": Default " << GREEN
				<< "constructor" << END << " called\n";
	return ;
}

Brain::Brain(std::string ids[100]) : ideas(ids)
{
	std::cout << GREEN << "Brain" << END << ": String " << GREEN
				<< "constructor" << END<< " called\n";
	return ;
}

Brain::~Brain(void)
{
	std::cout << GREEN << "Brain" << END << ": " << RED << "Destructor"
				<< END << " called\n";
}

Brain::Brain(const Brain &brain)
{
	std::cout << GREEN << "Brain" << END << ": Copy constructor called\n";
	*this = brain;
}

std::string	*Brain::getIdeas(void) const
{
	return (ideas);
}

Brain	&Brain::operator = (const Brain &brain)
{
	ideas = brain.getIdeas();
	std::cout << GREEN << "Brain" << END << ": Copy assignment operator called\n";
	return (*this);
}

void	Brain::setIdeas(const std::string ids[100])
{
	ideas = ids;
}