#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap a = ClapTrap("Anton");
	ClapTrap b( a );
	ClapTrap c("Colya");
	c = b;

	std::cout << a.getHp() << std::endl;
	std::cout << b.getEp() << std::endl;
	std::cout << c.getAd() << std::endl;

	b.attack("Bob");
	c.takeDamage(b.getAd());
	return 0;
}
