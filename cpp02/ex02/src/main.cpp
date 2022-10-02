#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	//std::cout << --a << std::endl;
	//std::cout << a << std::endl;
	//std::cout << a-- << std::endl;
	//std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	//const Fixed &c=Fixed(1.3f);
	//const Fixed &d=Fixed(4.2f);
	//std::cout << Fixed::min(c, d) << std::endl;
	//Fixed cc=Fixed(1.3f);
	//Fixed dd=Fixed(4.2f);
	//std::cout << Fixed::min(cc, dd) << std::endl;
	//const Fixed &r=Fixed(1.3f);
	//const Fixed &dc=Fixed(4.2f);
	//std::cout << Fixed::max(r, dc) << std::endl;
	//Fixed rc=Fixed(1.3f);
	//Fixed rd=Fixed(4.2f);
	//std::cout << Fixed::max(rc, rd) << std::endl;
	return 0;
}
