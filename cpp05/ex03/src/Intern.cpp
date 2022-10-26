#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern const &intern)
{
	*this = intern;
}

Intern	&Intern::operator = (Intern const &intern)
{
	//if (this == &intern)
	(void)intern;
	return (*this);
}

Intern::~Intern(void) {}

static Form	*shrub(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

static Form	*robot(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

static Form	*pardon(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

Form	*Intern::makeForm(std::string const &name, std::string const &target) const
{
	t_cnstrctr	cs[3]={&shrub, &robot, &pardon};
	std::string	str[3] = {"ShrubberyCreationForm", "RobotomyRequestForm",
						"PresidentialPardonForm"};

	for (int i=0; i < 3; ++i)
	{
		if (str[i] == name)
		{
			std::cout << "Intern creates " << str[i] << "!\n";
			return ((cs[i])(target));
		}
	}
	std::cout << "Intern does not create " << name << "!\n";
	return (NULL);
}
