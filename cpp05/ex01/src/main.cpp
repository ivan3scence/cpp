#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"

int	main(void)
{
	Form 		f("formular", false, 4);
	Bureaucrat	bob("Bob", 5);

	std::cout << f;
	std::cout << bob;

	bob.signForm(f);
	bob++;
	std::cout << bob;
	bob.signForm(f);

	std::cout << std::endl << f << std::endl;

	return (0);
}