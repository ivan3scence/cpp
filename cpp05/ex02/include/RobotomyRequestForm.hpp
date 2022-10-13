#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	std::string _target;
	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const &shrub);
	void	_draw(void) const;
public:
	RobotomyRequestForm(std::string const &target);
	virtual ~RobotomyRequestForm(void);
	RobotomyRequestForm	&operator = (RobotomyRequestForm const &shrub);

	void					execute(Bureaucrat const &executor) const;
	std::string				getTarget(void) const;
};

#endif