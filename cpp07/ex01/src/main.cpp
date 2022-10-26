#include "iter.hpp"
#include <iostream>

#define SIZE 5

template < typename T >
void	print(T elem)
{
	std::cout << elem << std::endl;
}

int main( void )
{
	int		integer[SIZE]={1,2,3,4,5};
	double	dbl[SIZE]={1,2,3,4,5};
	std::string	strs[SIZE]={"1","2","3","4","5"};

	iter(integer, SIZE, &print);
	std::cout << std::endl;
	iter(dbl, SIZE, &print);
	std::cout << std::endl;
	iter(strs, SIZE, &print);
}

// class Awesome
// {
// 	public:
// 	Awesome( void ) : _n( 42 ) { return; }
// 	int get( void ) const { return this->_n; }
// 	private:
// 	int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

// template< typename T >
// void print( T const & x ) { std::cout << x << std::endl; return; }
// int main() {
// 	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
// 	Awesome tab2[5];
// 	iter( tab, 5, print );
// 	iter( tab2, 5, print );
// return 0;
// }