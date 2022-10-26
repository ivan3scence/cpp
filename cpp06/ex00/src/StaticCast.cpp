#include "StaticCast.hpp"

Cast::Cast(void) {}

Cast::~Cast(void) {}

Cast::Cast(char *string) : _string(std::string(string))
{
	double	val;

	if (Cast::_limits(std::string(string)))
		return ;
	Cast::_overFlow(string);
	val = std::atof(string);
	if (val > INT_MAX || val < INT_MIN)
	{
		std::cerr << "int overflow!\n";
		exit(1);
	}
	if (!val && string[0] != '0')
	{
		Cast::_fromChar(string[0]);
		Cast::display();
		return ;
	}
	Cast::_fromDbl(val);
	Cast::display();
}

static int	which(std::string const &string)
{
	if (string == "inf" || string == "+inf"
		|| string == "inff" || string == "+inff")
		return (0);
	else if (string == "nan" || string == "nanf")
		return (1);
	else if (string == "-inf" || string == "-inff")
		return (2);
	return (3);
}

bool	Cast::_limits(std::string const &string)
{
	switch (which(string))
	{
		case 0:
			std::cout << "char: impossible.\nint: impossible.\nfloat: inff.\n"
							"double: inf.\n";
			return (1);
		case 1:
			std::cout << "char: impossible.\nint: impossible.\nfloat: nanf.\n"
							"double: nan.\n";
			return (1);
		case 2:
			std::cout << "char: impossible.\nint: impossible.\nfloat: -inff.\n"
							"double: -inf.\n";
			return (1);
		default:
			return (0);
	}
}

void	Cast::_overFlow(std::string const &string)
{
	int	start;
	int	i;
	int	sign;

	i = -1;
	sign = 0;
	while (string[++i] && std::isspace(string[i]))
		;
	if (string[i] == '-' || string[i] == '+')
	{
		++i;
		sign = 1;
	}
	start = i;
	while (string[++i] && std::isdigit(string[i]))
		;
	if (i - start > 10
		|| (i - start == 10 && !sign && std::strcmp(&string[start],
		"2147483647") > 0)
		|| (i - start == 10 && sign && std::strcmp(&string[start],
		"2147483648") > 0))
	{
		std::cerr << "int overflow!\n";
		exit(1);
	}
}

void	Cast::_fromChar(char ch)
{
	_ch = ch;
	_i = static_cast<int>(ch);
	_d = static_cast<double>(ch);
	_f = static_cast<float>(ch);
}

void	Cast::_fromDbl(double dbl)
{
	_d = dbl;
	_f = static_cast<float>(dbl);
	_i = static_cast<int>(dbl);
	if (_d < 0 || _d > 128)
		_ch = "\0";
	else
		_ch = static_cast<char>(_i);
}

void	Cast::display(void) const
{
	std::cout.precision(1);
	std::cout << "char: " << (_d > 0 && _d < 128 && std::isprint(_ch[0])
				? _ch : _d == DBL_MAX ? "impossible" : "Non displayable")
				<< ".\nint: " << std::fixed << _i << ".\nfloat: " << _f
				<< "f.\ndouble: " << std::fixed << _d << ".\n";
}

Cast::Cast(Cast const &cast)
{
	*this = cast;
}

Cast	&Cast::operator = (Cast const &cast)
{
	if (this == &cast)
		return (*this);
	_string = cast.getString();
	_ch = cast.getCh();
	_i = cast.getI();
	_d = cast.getD();
	return (*this);
}

std::string	Cast::getString(void) const
{
	return (_string);
}

std::string	Cast::getCh(void) const
{
	return (_ch);
}

int	Cast::getI(void) const
{
	return (_i);
}

float	Cast::getF(void) const
{
	return (_f);
}

double	Cast::getD(void) const
{
	return (_d);
}
