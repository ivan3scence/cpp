#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main( void ) {
	Animal	chimp;
	Animal	bear(chimp);
	Dog		woof;
	Dog		boba(woof);
	Dog		afrika;
	Cat		misha;

	afrika = boba;
	chimp.setType("Chimp");
	std::cout << chimp.getType() << std::endl;
	std::cout << woof.getType() << std::endl;
	std::cout << bear.getType() << std::endl;
	std::cout << boba.getType() << std::endl;
	std::cout << afrika.getType() << std::endl;
	std::cout << misha.getType() << std::endl;

	chimp.makeSound();
	afrika.makeSound();
	misha.makeSound();
	std::cout << "\n\n\n";

	const Animal* metaf = new Animal();
	const Animal* jf = new Dog();
	const Animal* fi = new Cat();
	std::cout << jf->getType() << " " << std::endl;
	std::cout << fi->getType() << " " << std::endl;
	fi->makeSound(); //will output the cat sound!
	jf->makeSound();
	metaf->makeSound();
	std::cout << "\n\n\n";

	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	Cat	lol;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the wronganimal sound!
	lol.makeSound(); //will output the cat sound!
	meta->makeSound();
	return 0;
}
