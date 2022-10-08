#ifndef __CAT_H__
#define __CAT_H__

# include <iostream>
# include "Animal.hpp"
# include "Dog.hpp"
# include "Brain.hpp"

class Cat : virtual public Animal
{
public:
	Cat(void);
	Cat(const Cat &ct);
	~Cat(void);
	Cat	&operator = (const Cat &animal);
	Cat	&operator = (const Dog &dog);

	void 	makeSound(void) const;
	Brain	&getBrain(void) const;

private:
	Brain	*_brain;
};

#endif
