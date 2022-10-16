#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void ) {
	ClapTrap a = ClapTrap("Anton");
	ScavTrap aa = ScavTrap("Jojo");
	FragTrap bob = FragTrap("Bob");
	DiamondTrap	dimon = DiamondTrap("Dimon");

	std::cout << std::endl << a.getAd() << std::endl;
	std::cout << aa.getHp() << std::endl;
	std::cout << bob.getEp() << std::endl << std::endl;
	std::cout << dimon.getHp() << std::endl;
	std::cout << dimon.getEp() << std::endl;
	std::cout << dimon.getAd() << std::endl << std::endl;

	bob.attack("Colya");
	a.takeDamage(bob.getAd());
	aa.attack("Anton");
	a.takeDamage(aa.getAd());
	aa.guardGate();
	bob.attack("Jojo");
	aa.takeDamage(bob.getAd());
	bob.highFivesGuys();

	dimon.attack("bob");
	bob.takeDamage(dimon.getAd());
	dimon.attack("bob");
	bob.takeDamage(dimon.getAd());
	dimon.attack("bob");
	bob.takeDamage(dimon.getAd());
	dimon.attack("bob");
	bob.takeDamage(dimon.getAd());
	dimon.whoAmI();
	dimon.beRepaired(1);
	return 0;
}
