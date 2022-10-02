#include "Point.hpp"

int main( void ) {
	Point a(0,0);
	Point b(2,2);
	Point c(2,0);
	Point p(0,0);
	
	std::cout << bsp(a, b, c, p) << std::endl;
	Point aa(0,0);
	Point bb(2,2);
	Point cc(2,0);
	Point pp(1,1);
	
	std::cout << bsp(aa, bb, cc, pp) << std::endl;
	Point aaa(0,0);
	Point bbb(2,2);
	Point ccc(2,0);
	Point ppp(3,3);
	
	std::cout << bsp(aaa, bbb, ccc, ppp) << std::endl;
	Point aaaa(0,0);
	Point bbbb(2,2);
	Point cccc(2,0);
	Point pppp(-1,0);
	
	std::cout << bsp(aaaa, bbbb, cccc, pppp) << std::endl;
}
