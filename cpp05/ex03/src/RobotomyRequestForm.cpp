#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(void)
		: Form("RobotomyRequestForm", 0, 72, 45),
		_target("no-target")
{
	std::rand();
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
		: Form("RobotomyRequestForm", 0, 72, 45), _target(target)
{
	std::rand(); //use current time as seed for random generator
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &shrub)
{
	*this = shrub;
}

RobotomyRequestForm	&RobotomyRequestForm::operator =
											(RobotomyRequestForm const &shrub)
{
	if (this == &shrub)
		return (*this);
	_target = shrub.getTarget();
	return (*this);
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->Form::checkExecGrade(executor.getGrade());
	std::cout << "**dr-dr**\t\t\t**dr-dr**\n\t...some drilling noses...\n**dr-dr**\t\t\t**dr-dr**\n";
	int rand = std::rand() % 2;
	if (rand)
		std::cout << "graz! " << _target << " was successfully robotomized\n";
	else
		std::cout << ">_< " << _target << "'s robotomy was failed\n";
}
