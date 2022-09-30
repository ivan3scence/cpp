#include "Fixed.hpp"

int	Fixed::_num=0;

Fixed::Fixed(void) : _integer(0)
{
	++_num;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int integer) : _integer(integer)
{
	++_num;
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

std::ostream	&opereator << (const std::ostream &os, const Fixed &fix) const
{
	return os;
}