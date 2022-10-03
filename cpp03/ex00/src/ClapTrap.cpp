#include "Fixed.hpp"

int	Fixed::_fr_bit=8;

Fixed::Fixed(void) : _integer(0)
{
	return ;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int integer) : _integer(integer)
{
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