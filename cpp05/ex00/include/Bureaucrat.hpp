#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# include <iostream>
# include <exception>

class Bureaucrat
{
protected:
	std::string	_name;
	int			_grade;
	Bureaucrat(void);
	void		_checkGrade(int grade);
public:
	Bureaucrat(const Bureaucrat &bur);
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat	&operator = (Bureaucrat const &bur);
	~Bureaucrat(void);

	std::string			getName(void) const;
	int					getGrade(void) const;
	Bureaucrat			operator ++ (void);
	Bureaucrat			operator ++ (int);
	Bureaucrat			operator -- (void);
	Bureaucrat			operator -- (int);

	class GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException(){}
			virtual const char	*what(void) const _NOEXCEPT
			{
				return ("GradeTooHighException: Grade is too high!");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			GradeTooLowException(){}
			virtual const char	*what(void) const throw()
			{
				return ("GradeTooLowException: Grade is too low!");
			}
	};
};

std::ostream	&operator << (std::ostream &os, const Bureaucrat &bur);

#endif
