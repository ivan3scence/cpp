#ifndef FORM_HPP
# define FORM_HPP

# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string _name;
	bool 		_signature;
	int const	_min_sign;
	int const	_min_exec;

public:
	Form(void);
	Form(std::string const &name, bool signature, int grade);
	Form(std::string const &name, bool signature, int sign_g, int exec_g);
	Form(Form const &form);
	virtual ~Form(void);
	Form	&operator = (Form const &form);

	void			checkSignGrade(int bur) const;
	void			checkExecGrade(int bur) const;
	std::string 	getName(void) const;
	bool			getSignature(void) const;
	int 			getMinGrade(void) const;
	int				getExecGrade(void) const;
	virtual void	beSigned(Bureaucrat const &bur);

	virtual void	execute(Bureaucrat const &executor) const =0;


	class TooHighException : public std::exception
	{
	public:
		TooHighException(){}
		virtual const char	*what(void) const _NOEXCEPT
		{
			return ("TooHighException: Grade is too high!");
		}
	};

	class TooLowException : public std::exception
	{
	public:
		TooLowException(){}
		virtual const char	*what(void) const throw()
		{
			return ("TooLowException: Grade is too low!");
		}
	};

	class NoSignException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return ("Form is not signed!\n");
		}
	};

};

std::ostream	&operator << (std::ostream &os, const Form &form);

#endif
