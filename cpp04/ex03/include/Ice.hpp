#ifndef __ICE_H__
# define __ICE_H__

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(const Ice &ice);
	~Ice(void);
	Ice	&operator = (Ice const &ice);

	Ice	*clone(void) const;
	void use(ICharacter& target);
};

#endif