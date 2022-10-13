#ifndef PRESIDENTALPARDONFORM_HPP
#define PRESIDENTALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	std::string 			_target;
	void					_draw(void) const;
	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const &shrub);
public:
	PresidentialPardonForm(std::string const &target);
	virtual ~PresidentialPardonForm(void);
	PresidentialPardonForm	&operator = (PresidentialPardonForm const &shrub);

	virtual void			execute(Bureaucrat const &executor) const;
	std::string				getTarget(void) const;
};

#endif