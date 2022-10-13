#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(void)
		: Form("PresidentialPardonForm", 0, 25, 5),
		_target("no-target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
		: Form("PresidentialPardonForm", 0, 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &shrub)
{
	*this = shrub;
}

PresidentialPardonForm	&PresidentialPardonForm::operator =
											(PresidentialPardonForm const &shrub)
{
	if (this == &shrub)
		return (*this);
	_target = shrub.getTarget();
	return (*this);
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->Form::checkExecGrade(executor.getGrade());
	std::cout << _target << " was pardoned by  Zaphod Beeblebrox!\n";
}