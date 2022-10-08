#ifndef __WRONGANIMAL_H__
#define __WRONGANIMAL_H__

# include <iostream>
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define GRAY "\x1B[90m"
# define END "\033[0m"

class WrongAnimal
{
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &animal);
	~WrongAnimal(void);
	WrongAnimal(std::string type);
	WrongAnimal	&operator = (const WrongAnimal &animal);

	std::string		getType(void) const;
	void	makeSound(void) const;
	void			setType(const std::string type);
protected:
	std::string			_type;
};

#endif
