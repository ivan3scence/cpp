#include "Intern.hpp"

int	main(void)
{
	std::srand(time(NULL));

	Intern	bOb;
	Form	*someForm;

	someForm = bOb.makeForm("PresidentialPardonForm", "country");
	std::cout << someForm->getName() << std::endl;
	std::cout << someForm->getMinGrade() << std::endl;
	std::cout << someForm->getExecGrade() << std::endl;
	std::cout << someForm->getSignature() << std::endl;
	Bureaucrat	vanO("Ivan", 8);
	vanO.signForm(*someForm);
	//someForm->beSigned(vanO);
	std::cout << someForm->getSignature() << std::endl;
	delete someForm;
}