#ifndef __WRONGCAT_H__
#define __WRONGCAT_H__

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(const WrongCat &ct);
	~WrongCat(void);
	WrongCat	&operator = (const WrongCat &animal);

	void makeSound(void) const;
};

#endif
