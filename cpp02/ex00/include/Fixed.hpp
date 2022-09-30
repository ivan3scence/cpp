#ifndef __FIXED_H__
#define __FIXED_H__

# include <iostream>

class Fixed
{
public:

	Fixed(void);
	Fixed(const Fixed &fix);
	~Fixed(void);
	Fixed(int integer);

	Fixed	&operator = (const Fixed &fix)
	{
		std::cout << "Copy assignment operator called\n";
		if (this == &fix)
            return *this;
		_integer = fix.getRawBits();
		return (*this);
	}

	int			getRawBits(void) const;
	void		setRawBits(int const raw);

private:
	static int	_num;
	int			_integer;
};

#endif
