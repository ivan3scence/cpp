#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
	ClapTrap a = ClapTrap("Anton");
	ScavTrap aa = ScavTrap("Jojo");
	FragTrap bob = FragTrap("Bob");
	FragTrap bob2 = FragTrap(bob);
	FragTrap bob3 = FragTrap("Bob", 123, 50, 7);
	ClapTrap b( a );
	ScavTrap bb( aa );
	ScavTrap c("Colya", 1, 2, 3);
	c = bb;
	bob = bob3;

	std::cout << aa.getHp() << std::endl;
	std::cout << bob.getEp() << std::endl;
	std::cout << c.getAd() << std::endl;

	b.attack("Colya");
	c.takeDamage(b.getAd());
	aa.attack("Anton");
	a.takeDamage(aa.getAd());
	aa.guardGate();
	bob.attack("Bob2");
	bob2.takeDamage(bob.getAd());
	bob3.highFivesGuys();
	return 0;
}
