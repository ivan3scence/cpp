#ifndef __CURE_H__
# define __CURE_H__

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(const Cure &cure);
	~Cure(void);
	Cure	&operator = (Cure const &ice);

	Cure	*clone(void) const;
	void use(ICharacter& target);
};

#endif