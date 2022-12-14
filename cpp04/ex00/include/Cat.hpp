#ifndef __CAT_H__
#define __CAT_H__

# include <iostream>
# include "Animal.hpp"

class Cat : virtual public Animal
{
public:
	Cat(void);
	Cat(const Cat &ct);
	~Cat(void);
	Cat	&operator = (const Cat &animal);

	void makeSound(void) const;
};

#endif
