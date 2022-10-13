#include "Form.hpp"

Form::Form(void) : _name("noname"), _signature(0), _min_grade(0){}

Form::Form(std::string const &name, bool signature, int grade) : _name(name),
			_signature(signature), _min_grade(grade) {}

Form::Form(Form const &form)
{
	*this = form;
}

Form	&Form::operator = (Form const &form)
{
	if (this == &form)
		return (*this);
	_name = form.getName();
	_signature = form.getSignature();
	_min_grade = form.getMinGrade();
	return (*this);
}

Form::~Form(void) {}

std::string Form::getName(void) const
{
	return (_name);
}

bool	Form::getSignature(void) const
{
	return (_signature);
}

int		Form::getMinGrade(void) const
{
	return (_min_grade);
}

void 	Form::beSigned(Bureaucrat const &bur)
{
	Form::_checkGrade(bur.getGrade());
	_signature = true;
}

void	Form::_checkGrade(int bur)
{
	if (bur < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (bur > 150)
		throw Bureaucrat::GradeTooLowException();
	if (bur > _min_grade)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream	&operator << (std::ostream &os, const Form &form)
{
	os << form.getName() << " form's signature <"
							<< (form.getSignature() ? "true": "false")
							<< ">, form's min_grade " << form.getMinGrade()
							<< ".\n";
	return (os);
}
