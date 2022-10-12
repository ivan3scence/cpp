#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# include <iostream>

class Bureaucrat
{
private:
	std::string	_name;
	int					_grade;
public:
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat &bur);
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat	&operator = (Bureaucrat const &bur);
	~Bureaucrat(void);

	void				GradeTooHighException(void);
	void				GradeTooLowException(void);
	std::string			getName(void) const;
	int					getGrade(void) const;
	//void				checkGrade(int grade);
	Bureaucrat			operator ++ (void);
	Bureaucrat			operator ++ (int);
	Bureaucrat			operator -- (void);
	Bureaucrat			operator -- (int);

	class GradeTooHighException : public std::exception
	{
		public:
			const char	*what() const throw()
			{
				return ("GradeTooHighException: Grade is too high!");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char	*what() const throw()
			{
				return ("GradeTooLowException: Grade is too low!");
			}
	};
};

#endif
