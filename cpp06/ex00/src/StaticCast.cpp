#include "StaticCast.hpp"

Cast::Cast(void) {}

Cast::~Cast(void) {}

Cast::Cast(char *string) : _string(std::string(string))
{
	double	val;

	Cast::_overFlow(string);
	val = std::atof(string);
	if (!val && string[0] != '0')
		Cast::_fromChar(string[0]);
	Cast::_fromDbl(val);
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
		std::cout << "int overflow!\n";
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
		_ch = static_cast<char>(_i);
}

void	Cast::display(void) const
{
	std::cout << "char: " << (_d > 0 && _d < 128 && std::isprint(_ch) ? &_ch
				: "Non displayable")
				<< ".\nint: " << _i << ".\nfloat: " << _f << "f.\ndouble: "
				<< _d << ".\n";
}

//int	Cast::getType(std::string const &string)
//{
//	double	val;
//
//	if (string[0].isalpha())
//		return (CHAR);
//	val = std::atof(string);
//
//}

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

char	Cast::getCh(void) const
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
