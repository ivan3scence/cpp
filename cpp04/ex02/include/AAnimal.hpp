#ifndef __AANIMAL_H__
#define __AANIMAL_H__

# include <iostream>
# include "Brain.hpp"

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define GRAY "\x1B[90m"
# define END "\033[0m"

class AAnimal
{
public:
//	AAnimal(void);
//	virtual AAnimal(const AAnimal &animal);
	virtual ~AAnimal(void) =0;
//	AAnimal(std::string type);
//	virtual AAnimal	&operator = (const AAnimal &animal);

//	std::string		getType(void) const;
	virtual void	makeSound(void) const;
//	void			setType(const std::string type);
protected:
	std::string			_type;
};

AAnimal::~AAnimal(void) {}

#endif
