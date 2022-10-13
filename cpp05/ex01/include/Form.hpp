#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string _name;
	bool 		_signature;
	int 		_min_grade;
	Form(void);
	void		_checkGrade(int bur);

public:
	Form(std::string const &name, bool signature, int grade);
	Form(Form const &form);
	~Form(void);
	Form	&operator = (Form const &form);

	std::string getName(void) const;
	bool 		getSignature(void) const;
	int 		getMinGrade(void) const;
	void 		beSigned(Bureaucrat const &bur);
};

std::ostream	&operator << (std::ostream &os, const Form &form);

#endif
