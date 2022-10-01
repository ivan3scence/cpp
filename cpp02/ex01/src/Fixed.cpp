#include "Fixed.hpp"

int	Fixed::_fr_bit=8;

Fixed::Fixed(void) : _integer(0)
{
	std::cout << "Default constructor called\n";
	return ;
}

Fixed::Fixed(const int integer) : _integer(integer << _fr_bit)
{
	return ;
}

int		Fixed::shift(float flt) const
{
	std::cout << "lol " << flt << "\n";
	while (flt - (int)flt > 0)
		flt *= 10;
	std::cout << "lol2 " << flt << std::endl;
	return ((int)flt);
}

Fixed::Fixed(const float flt)
{
	int		zel = 0;

	_integer = 0;
	zel |= (int)flt << _fr_bit;
	_integer = zel | (Fixed::shift(flt - (int)flt));
	std::cout << _integer << std::endl;
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

float	Fixed::shift_back(float frl) const
{
	while (frl >= 1)
		frl /= 10.0;
	return (frl);
}

float	Fixed::toFloat(void) const
{
	float	flt;

	flt = (_integer >> _fr_bit) + shift_back(_integer << (32 - _fr_bit)
			>> (32 - _fr_bit));
	return (flt);
}

int	Fixed::toInt(void) const
{
	int ret;

	ret = _integer >> _fr_bit;
	return (ret);
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
