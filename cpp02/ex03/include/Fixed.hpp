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
	Fixed	operator + (const Fixed &fix);
	Fixed	operator - (const Fixed &fix);
	Fixed	operator * (const Fixed &fix);
	Fixed	operator / (const Fixed &fix);

	Fixed	operator ++ (void);
	Fixed	operator ++ (int plus);
	Fixed	operator -- (void);
	Fixed	operator -- (int plus);
	
	bool	operator == (const Fixed &fix) const;
	bool	operator != (const Fixed &fix) const;
	bool	operator > (const Fixed &fix) const;
	bool	operator < (const Fixed &fix) const;
	bool	operator <= (const Fixed &fix) const;
	bool	operator >= (const Fixed &fix) const;

	static Fixed	&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);

	int			getRawBits(void) const;
	void		setRawBits(int const raw);
	int			getInteger(void) const;
	int			getFr_bit(void) const;
	float		toFloat(void) const;
	int			toInt(void) const;
private:
	static int	_fr_bit;
	int			_integer;
};

std::ostream	&operator << (std::ostream &os, const Fixed &fix);
#endif
