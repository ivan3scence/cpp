#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "Form.hpp"

int	main(void)
{
	std::srand(time(NULL));
//	ShrubberyCreationForm	shrub("home");
//	Bureaucrat	bob("bob", 1);
//	bob.signForm(shrub);
//	shrub.execute(bob);
//
//	RobotomyRequestForm	rob("arm");
//	bob.signForm(rob);
//	rob.execute(bob);
//
//	PresidentialPardonForm	pardon("Lexa");
//	bob.signForm(pardon);
//	bob.executeForm(pardon);

	try
	{
		ShrubberyCreationForm	shrub2("garden");
		Bureaucrat	bob2("bob2", 1);
		shrub2.execute(bob2);
	}
	catch (std::exception &e)
	{
		e.what();
	}

	try
	{
		RobotomyRequestForm	rob2("leg");
		Bureaucrat	bob3("bob3", 150);
		bob3.signForm(rob2);
		rob2.execute(bob3);
	}
	catch (std::exception &e)
	{
		e.what();
	}

	try
	{
		PresidentialPardonForm	pardon2("Dima");
		Bureaucrat	bob4("bob4", 20);
		bob4.signForm(pardon2);
		bob4.executeForm(pardon2);
	}
	catch (std::exception &e)
	{
		e.what();
	}

}