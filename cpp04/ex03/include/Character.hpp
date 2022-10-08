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
	~Character(void);
	Character(void);
	Character(const Character &character);
	Character	&operator = (Character const &character);

	std::string const & getName() const = 0;
	void		equip(AMateria* m) = 0;
	void		unequip(int idx) = 0;
	void		use(int idx, ICharacter& target) = 0;
	bool		ifExists(int idx);
	void 		getMaterias(AMateria* (&to)[4]) const;
};

#endif
