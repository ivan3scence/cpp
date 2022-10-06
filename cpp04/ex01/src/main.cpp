#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
	ClapTrap a = ClapTrap("Anton");
	ScavTrap aa = ScavTrap("Jojo");
	ClapTrap b( a );
	ScavTrap bb( aa );
	ScavTrap c("Colya", 1, 2, 3);
	c = bb;

	std::cout << aa.getHp() << std::endl;
	std::cout << b.getEp() << std::endl;
	std::cout << c.getAd() << std::endl;

	b.attack("Colya");
	c.takeDamage(b.getAd());
	aa.attack("Anton");
	a.takeDamage(aa.getAd());
	aa.guardGate();
	return 0;
}
