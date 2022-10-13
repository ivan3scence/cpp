#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Form;

class Intern
{
public:
	Intern(void);
	//Intern(std::string const &name, std::string const &target);
	Intern(Intern const &intern);
	Intern	&operator = (Intern const &intern);
	~Intern(void);

	Form	*makeForm(std::string const &name, std::string const &target) const;
};

typedef Form	*(*t_cnstrctr)(std::string const &);

#endif