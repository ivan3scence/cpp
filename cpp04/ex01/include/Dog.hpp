#ifndef __DOG_H__
#define __DOG_H__

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : virtual public Animal
{
public:
	Dog(void);
	Dog(const Dog &ct);
	~Dog(void);
	Dog	&operator = (const Dog &animal);

	void makeSound(void) const;
	Brain	&getBrain(void) const;
private:
	Brain	*_brain;
};

#endif
