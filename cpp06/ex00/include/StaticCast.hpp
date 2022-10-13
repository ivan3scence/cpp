#ifndef STATIC_CAST_HPP
#define STATIC_CAST_HPP

# include <iostream>
# include <cstring>

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3

class Cast
{
protected:
	std::string _string;
	char 		_ch;
	int 		_i;
	float 		_f;
	double		_d;
	void		_fromDbl(double dbl);
	void		_fromChar(char ch);
	void		_overFlow(std::string const &string);
	Cast(void);

public:
	Cast(char *string);
	~Cast(void);
	Cast(Cast const &cast);
	Cast	&operator = (Cast const &cast);

	int 		getType(std::string const &string);
	void 		display(void) const;
	double		getD(void) const;
	int			getI(void) const;
	float		getF(void) const;
	char		getCh(void) const;
	std::string	getString(void) const;
};

#endif
