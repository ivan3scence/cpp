#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	std::string _target;
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const &shrub);
	void	_draw(void) const;
public:
	ShrubberyCreationForm(std::string const &target);
	virtual ~ShrubberyCreationForm(void);
	ShrubberyCreationForm	&operator = (ShrubberyCreationForm const &shrub);

	void					execute(Bureaucrat const &executor) const;
	std::string				getTarget(void) const;
};

#endif