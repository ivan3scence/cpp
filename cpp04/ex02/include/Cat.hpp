#ifndef __CAT_H__
#define __CAT_H__

# include <iostream>
# include "AAnimal.hpp"
# include "Dog.hpp"
# include "Brain.hpp"

class Cat : virtual public AAnimal
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
