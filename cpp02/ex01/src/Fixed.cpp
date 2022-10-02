#include "Fixed.hpp"

int	Fixed::_fr_bit=8;

Fixed::Fixed(void) : _integer(0)
{
	std::cout << "Default constructor called\n";
	return ;
}

Fixed::Fixed(const int integer) : _integer(integer << _fr_bit)
{
	std::cout << "Int constructor called\n";
	return ;
}

Fixed::Fixed(const float flt) : _integer((int)roundf(flt * (1 << _fr_bit)))
{
	std::cout << "Float constructor called\n";
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &fix)
{
	std::cout << "Copy constructor called\n";
	*this = fix;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (_integer);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	_integer = raw;
}

float	Fixed::toFloat(void) const
{

	return ((float)_integer / (1 << _fr_bit));
}

int	Fixed::toInt(void) const
{
	return (_integer >> _fr_bit);
}

int		Fixed::getInteger(void) const
{
	return (_integer);
}

int		Fixed::getFr_bit(void) const
{
	return (_fr_bit);
}

Fixed	&Fixed::operator = (const Fixed &fix)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &fix)
        return *this;
	_integer = fix.getRawBits();
	return (*this);
}

std::ostream	&operator << (std::ostream &os, const Fixed &fix)
{
	os << fix.toFloat();
	return (os);
}
