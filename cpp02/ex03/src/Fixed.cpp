#include "Fixed.hpp"

int	Fixed::_fr_bit=8;

Fixed::Fixed(void) : _integer(0)
{
	return ;
}

Fixed::Fixed(const int integer) : _integer(integer << _fr_bit)
{
	return ;
}

Fixed::Fixed(const float flt) : _integer((int)roundf(flt * (1 << _fr_bit)))
{
	return ;
}

Fixed::~Fixed(void)
{
    return ;
}

Fixed::Fixed(const Fixed &fix)
{
	*this = fix;
}

int		Fixed::getRawBits(void) const
{
	return (_integer);
}

void	Fixed::setRawBits(int const raw)
{
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

Fixed	Fixed::operator + (const Fixed &fix)
{
	Fixed	sum(this->toFloat() + fix.toFloat());

	return (sum);
}

Fixed	Fixed::operator ++ (void)
{
	++_integer;
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed	newfix = *this;

	++_integer;
	return (newfix);
}

Fixed	Fixed::operator -- (void)
{
	--_integer;
	return (*this);
}

Fixed	Fixed::operator -- (int)
{
	Fixed	newfix = *this;

	--_integer;
	return (newfix);
}

Fixed	Fixed::operator - (const Fixed &fix)
{
	Fixed	dif(this->toFloat() - fix.toFloat());

	return (dif);
}

Fixed	Fixed::operator * (const Fixed &fix)
{
	Fixed	mult(this->toFloat() * fix.toFloat());

	return (mult);
}

Fixed	Fixed::operator / (const Fixed &fix)
{
	Fixed	div(this->toFloat() / fix.toFloat());

	return (div);
}

bool	Fixed::operator == (const Fixed &fix) const
{
	return (this->toFloat() == fix.toFloat());
}

bool	Fixed::operator != (const Fixed &fix) const
{
	return (this->toFloat() != fix.toFloat());
}

bool	Fixed::operator >= (const Fixed &fix) const
{
	return (this->toFloat() >= fix.toFloat());
}

bool	Fixed::operator <= (const Fixed &fix) const
{
	return (Fixed::toFloat() <= fix.toFloat());
}

bool	Fixed::operator > (const Fixed &fix) const
{
	return (this->toFloat() > fix.toFloat());
}

bool	Fixed::operator < (const Fixed &fix) const
{
	return (this->toFloat() < fix.toFloat());
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}
