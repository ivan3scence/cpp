#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	_grade = 150;
	return ;
}

//void	Bureaucrat::checkGrade(int grade)
//{
//	if (grade < 1)
//		throw GradeTooHighException();
//	if (grade > 150)
//		throw GradeTooLowException();
//}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	//Bureaucrat::checkGrade(grade);
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur)
{
	*this = bur;
}

Bureaucrat	&Bureaucrat::operator = (const Bureaucrat &bur)
{
	if (this == &bur)
		return (*this);
	_grade = bur.getGrade();
	_name = bur.getName();
	return (*this);
}

int		Bureaucrat::getGrade(void) const
{
	return (_grade);
}

std::string		Bureaucrat::getName(void) const
{
	return (_name);
}

Bureaucrat	Bureaucrat::operator ++ (void)
{
	//checkGrade(_grade - 1);
	--_grade;
	return (*this);
}

Bureaucrat	Bureaucrat::operator ++ (int)
{
	//checkGrade(_grade - 1);
	Bureaucrat	new_bur = *this;
	--_grade;
	return (new_bur);
}

Bureaucrat	Bureaucrat::operator -- (void)
{
	//checkGrade(_grade + 1);
	++_grade;
	return (*this);
}

Bureaucrat	Bureaucrat::operator -- (int)
{
	//checkGrade(_grade + 1);
	Bureaucrat	new_bur = *this;
	++_grade;
	return (new_bur);
}

