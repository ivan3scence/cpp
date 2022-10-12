#include "Bureaucrat.hpp"

int		main(void)
{
	Bureaucrat	bob("Bob", 13);
	try
	{
		Bureaucrat	ann("Ann", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	//Bureaucrat	vlad("Vlad", 0);
	//
	//std::cout << "\tname: " << bob.getName() << "\tgrade: " << bob.getGrade() << std::endl;
	//std::cout << "\tname: " << ann.getName() << "\tgrade: " << ann.getGrade() << std::endl;
	//std::cout << "\tname: " << vlad.getName() << "\tgrade: " << vlad.getGrade() << std::endl;
	//vlad = bob;
	//std::cout << "\tname: " << vlad.getName() << "\tgrade: " << vlad.getGrade() << std::endl;
}
