#include "Fixed.hpp"

int main( void ) {
	Fixed	a;
	int		aa=4;
	Fixed	b(aa);
	float	cc=3.5;
	Fixed	c(cc);
	float	d=3.9;

	std::cout << (int)d << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
}
