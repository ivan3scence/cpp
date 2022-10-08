#include "Character.hpp"

Character::~Character(void)
{
	return ;
}

Character::Character(std::string const &n) : _name(n)
{
	return ;
}

Character::Character(const Character &character)
{
	*this = character;
}

Character	&Character::operator = (Character const &character)
{
	if (this == &character)
		return (*this);
	character.getMaterias(_materias);
	_name = character.getName();
	return (*this);
}

void	Character::getMaterias(AMateria* (&to)[4]) const
{
	for (int i=0; i < 4; ++i)
		to[i] = _materias[i];
}

std::string const	&Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria *m)
{
	for (int i=0; i < 4; ++i)
	{
		if (!_materias[i])
			_materias[i] = m;
	}
}

bool	Character::ifExists(int idx)
{
	if (_materias[idx])
		return (true);
	return (false);
}

void	Character::unequip(int idx)
{
	if (!Character::ifExists(idx))
	{
		std::cout << "treing to delete unexisting slot!\n";
		return ;
	}
	delete _materias[idx];
	_materias[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (!Character::ifExists(idx))
		_materias[idx]->use(target);
	else
		std::cout << "trying to use unexisting slot!\n";
}