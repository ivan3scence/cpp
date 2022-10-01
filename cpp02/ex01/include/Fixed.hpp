#ifndef __FIXED_H__
#define __FIXED_H__

# include <iostream>
# include <cmath>

class Fixed
{
public:

	Fixed(void);
	Fixed(const Fixed &fix);
	~Fixed(void);
	Fixed(const int integer);
	Fixed(const float flt);


	Fixed	&operator = (const Fixed &fix);


	int			getRawBits(void) const;
	void		setRawBits(int const raw);
	int			getInteger(void) const;
	int			getFr_bit(void) const;
	float		toFloat(void) const;
	int			toInt(void) const;
	int			shift(float flt) const;
	float		shift_back(float frl) const;
private:
	static int	_fr_bit;
	int			_integer;
};

std::ostream	&operator << (std::ostream &os, const Fixed &fix);
#endif
