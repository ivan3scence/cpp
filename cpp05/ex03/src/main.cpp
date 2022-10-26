#include "Intern.hpp"

int	main(void)
{
	std::srand(time(NULL));

	Intern	bOb;
	Form	*someForm;

	someForm = bOb.makeForm("PresidentialPardonForm", "country");
	std::cout << std::endl << someForm->getName() << std::endl;
	std::cout << someForm->getMinGrade() << std::endl;
	std::cout << someForm->getExecGrade() << std::endl;
	std::cout << someForm->getSignature() << std::endl << std::endl;
	Bureaucrat	vanO("Ivan", 8);
	try
	{
		vanO.signForm(*someForm);
		std::cout << someForm->getSignature() << std::endl;
		vanO.executeForm(*someForm);
	}
	catch (std::exception &e)
	{
		e.what();
	}
	delete someForm;
}