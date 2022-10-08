#include "Brain.hpp"

void	copy_array(std::string *a1, const std::string *a2, int count)
{
	for (int i=0; i < count; ++i)
		a1[i] = a2[i];
}

Brain::Brain(void)
{
	std::cout << GRAY << "Brain" << END << ": Default " << GRAY
				<< "constructor" << END << " called\n";
	return ;
}

Brain::Brain(std::string name)
{
	std::cout << GRAY << "Brain" << END << ": String " << GRAY
			  << "constructor" << END << " called\n";
	for (int i=0; i < 100; ++i)
		ideas[i] = name;
}

Brain::Brain(std::string ids[100])
{
	std::cout << GRAY << "Brain" << END << ": Array " << GRAY
				<< "constructor" << END<< " called\n";
	copy_array(ideas, ids, 100);
	return ;
}

Brain::~Brain(void)
{
	std::cout << GRAY << "Brain" << END << ": " << RED << "Destructor"
				<< END << " called\n";
}

Brain::Brain(const Brain &brain)
{
	std::cout << GRAY << "Brain" << END << ": Copy constructor called\n";
	*this = brain;
}

Brain	&Brain::operator = (const Brain &brain)
{
	copy_array(ideas, brain.ideas, 100);
	std::cout << GRAY << "Brain" << END << ": Copy assignment operator called\n";
	return (*this);
}

void	Brain::setIdeas(const std::string ids[100])
{
	copy_array(ideas, ids, 100);
}

void	Brain::print(void) const
{
	std::cout << ideas[0];
}