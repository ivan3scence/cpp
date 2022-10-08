#ifndef __CHARACTER_H__
# define __CHARACTER_H__

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	AMateria	*_materias[4];
	std::string	_name;

public:
	Character(std::string const &n);
	virtual ~Character(void);
	Character(void);
	Character(const Character &character);
	Character	&operator = (Character const &character);

	std::string const & getName() const;
	void		equip(AMateria* m);
	void		unequip(int idx);
	void		use(int idx, ICharacter& target);
	bool		ifExists(int idx);
	void 		getMaterias(AMateria* (&to)[4]) const;
};

#endif
