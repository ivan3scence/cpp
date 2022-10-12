#ifndef __AMATERIA_H__
#define __AMATERIA_H__

# include <iostream>
# include "ICharacter.hpp"

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define GRAY "\x1B[90m"
# define END "\033[0m"

class AMateria
{
protected:
	std::string	_type;

public:
	AMateria(void);
	AMateria(const AMateria &amateria);
	AMateria	&operator = (AMateria const &amateria);
	virtual	~AMateria(void);
	AMateria(std::string const & type);

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) =0;
};

#endif
