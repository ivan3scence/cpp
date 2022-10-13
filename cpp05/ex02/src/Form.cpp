#include "Form.hpp"

Form::Form(void) : _name("noname"), _signature(0), _min_sign(0), _min_exec(0){}

Form::Form(std::string const &name, bool signature, int grade) : _name(name),
			_signature(signature), _min_sign(grade), _min_exec(0) {}

Form::Form(std::string const &name, bool signature, int sign_g, int exec_g)
			: _name(name), _signature(signature),
			_min_sign(sign_g), _min_exec(exec_g) {}

Form::Form(Form const &form) : _min_sign(0), _min_exec(0)
{
	*this = form;
}

Form	&Form::operator = (Form const &form)
{
	if (this == &form)
		return (*this);
	_name = form.getName();
	_signature = form.getSignature();
//	_min_sign = form.getMinGrade();
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
	return (_min_sign);
}

void 	Form::beSigned(Bureaucrat const &bur)
{
	Form::checkSignGrade(bur.getGrade());
	_signature = true;
}

void	Form::checkSignGrade(int bur) const
{
	if (bur < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (bur > 150)
		throw Bureaucrat::GradeTooLowException();
	if (bur > _min_sign)
		throw Bureaucrat::GradeTooLowException();
}

int	Form::getExecGrade(void) const
{
	return (_min_exec);
}

void	Form::checkExecGrade(int bur) const
{
	if (!this->getSignature())
		throw Form::NoSignException();
	if (bur > this->getExecGrade())
		throw Form::TooLowException();
}

std::ostream	&operator << (std::ostream &os, const Form &form)
{
	os << form.getName() << " form's signature <"
							<< (form.getSignature() ? "true": "false")
							<< ">, form's min_sign " << form.getMinGrade()
							<< ".\n";
	return (os);
}

